#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_W 501
#define MAX_F 261

int main(int argc, char *argv[])
{
    char *string;
    char frep[MAX_F];
    strcpy(frep, argv[1]); // stores fname in frep[], clears stdin
    FILE *rep = fopen(frep, "r");
    FILE *tmp = fopen("Temp.txt", "w"); // opens file for reading and tmp for writing
    if (rep == NULL || tmp == NULL)
    {
        perror("\nError in opening files");
    }
    else
    {
        char target[MAX_W];
        strcpy(target, argv[2]);

        int length = strlen(argv[2]);
        string = malloc(length+1);
        strcpy(string, argv[2]);
        //Capitalize the user input string
        for (int i = 0; string[i] != '\0'; i++)
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] = string[i] - 32;
            }   
        }

        //Stores the capitalized string into replace[]
        char replace[MAX_W];
        strcpy(replace, string);
        while (1)
        {
            int ch = fgetc(rep);
            if (ch == EOF)
                break;
            else if (ch == ' ' || ch == '\t' || ch == '\n') //Write directly any whitespace/ tab/ newline chars
                fputc(ch, tmp);
            else
            {
                char buffer[MAX_W];
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
