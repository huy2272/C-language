#include <stdio.h>
#include <string.h>
#define MAX_W 501
#define MAX_F 261

void eat(void); // clears stdin

int main(int argc, char *argv[])
{
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
        char replace[MAX_W];
        strcpy(replace, &toUpper(target));
        while (1)
        {
            int ch = fgetc(rep);
            if (ch == EOF)
                break;
            else if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
                fputc(ch, tmp); // directly write whitespace chars
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
                printf("\nSuccess.\n\nReplaced any instances of \"%s\" with \"%s\".\n", target, replace);
            else
            {
                remove(frep);
                if (rename("Temp.txt", frep) == 0)
                    printf("\nSucess.\n\nReplaced any instances of \"%s\" with \"%s\".\n", target, replace);
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
