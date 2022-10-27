#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int SrchAndReplace(int argc, char *argv[])
{
    char *string;
    char frep[FILENAME_MAX];
    strcpy(frep, argv[1]); // stores fname in frep[], clears stdin
    FILE *rep = fopen(frep, "r");
    FILE *tmp = fopen("Temp.txt", "w"); // opens file for reading and tmp for writing
    if (rep == NULL || tmp == NULL)
    {
        perror("\nError in opening files");
    }
    else
    {
        char target[FILENAME_MAX];
        strcpy(target, argv[2]);

        int length = strlen(argv[2]);
        string = malloc(length + 1);
        strcpy(string, argv[2]);
        // Capitalize the user input string
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = string[i] - 32;
            }
        }

        // Stores the capitalized string into replace[]
        char replace[FILENAME_MAX];
        strcpy(replace, string);
        while (1)
        {
            int ch = fgetc(rep);
            if (ch == EOF)
                break;
            else if (ch == ' ' || ch == '\t' || ch == '\n') // Write directly any whitespace/ tab/ newline chars
                fputc(ch, tmp);
            else
            {
                char buffer[FILENAME_MAX];
                fseek(rep, -1, SEEK_CUR);
                // move FILE pointer 1 byte back to read entire word, not from 2nd char onwards
                fscanf(rep, "%500s", buffer);
                if (strcmp(buffer, target) == 0)
                    strcpy(buffer, replace);
                fprintf(tmp, "%s", buffer);
            }
        }
        fclose(rep);
        int chk = fclose(tmp);
        if (chk == EOF)
        {
            remove("Temp.txt");
            perror("\nFailed ");
        }
        else
        {
            if (rename("Temp.txt", frep) == 0)
                printf("\nSuccess!\nReplaced instances of \"%s\" with \"%s\".\n", target, replace);
            else
            {
                remove(frep);
                if (rename("Temp.txt", frep) == 0)
                    printf("\nSuccess.\nReplaced any instances of \"%s\" with \"%s\".\n", target, replace);
                else
                {
                    remove("Temp.txt");
                    perror("\nFailed ");
                }
            }
        }
    }
    return 0;
}

int Srch(char *fname, char *str){
    FILE *fp, *fp1;
    int line_num = 1;
    int hits = 0;
    char buffer[513];
    char ch;


    fp = fopen(fname,"r");
    if (fp == NULL)
        return -1;
    
    while ((fgets(buffer, 512, fp)) != NULL)
    {
        ch = fgetc(fp);
        if ((strstr(buffer, str)) != NULL)
        {
            ch = ch - 32;
            printf("There's a match on line: %d\n", line_num);
            printf("%s\n", buffer);
            hits++;
        }
        fputc(ch, fp1);
        line_num++;   
    }

    if (hits == 0)
        printf("No matches found in this file\n");
    else
        printf("Number of hits: %d\n", hits);
        
    fclose(fp);
    fclose(fp1);
    fp = NULL;
    fp1 = NULL;
    // Report(hits, fname, str);
    
    return 0;
}