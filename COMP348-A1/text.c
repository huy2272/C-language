#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "methods.h"

int SrchAndReplace(char *fname, const char *argv)
{
    Count(fname, argv);
    char *string;
    char frep[FILENAME_MAX];
    strcpy(frep, fname); // stores fname in frep[], clears stdin
    FILE *rep = fopen(frep, "r");
    FILE *tmp = fopen("Temp.txt", "w"); // opens file for reading and tmp for writing
    if (rep == NULL || tmp == NULL)
    {
        perror("\nError in opening files");
    }
    else
    {
        char target[FILENAME_MAX];
        strcpy(target, argv);

        int length = strlen(argv);
        string = malloc(length + 1);
        strcpy(string, argv);
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
                printf("%s was checked.\n", fname);
            else
            {
                remove(frep);
                if (rename("Temp.txt", frep) != 0){
                    remove("Temp.txt");
                    perror("\nFailed ");
                }
            }
        }
    }
    return 0;
}

int Count(char *fname, const char *str){
    FILE *fp;
    int hits = 0;
    int length = strlen(str);
    char buffer[length+1];

    fp = fopen(fname, "r");
    if (fp == NULL)
        return -1;

    while ((fgets(buffer, length, fp)) != NULL)
    {
        if ((strstr(buffer, str)) != NULL)
        {
            printf("%s\n", buffer);
            hits++;
        }
    }

    if (hits != 0)
        printf("Updated %d", hits);
    
    fclose(fp);
    fp = NULL;
    Report(hits, fname, str);
    
    return 0;
}
