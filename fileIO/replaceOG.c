#include <stdio.h>
#include <string.h>
#define MAX_W 501
#define MAX_F 261

void eat(void); // clears stdin

int main()
{
    printf("\nKeep a backup of your file in case of undesirable effects.\n");
    char frep[MAX_F];
    printf("\n Filename : ");
    scanf("%260[^\n]", frep);
    eat(); // stores fname in frep[], clears stdin
    FILE *rep = fopen(frep, "r");
    FILE *tmp = fopen("Temp.Ctt", "w"); // opens file for reading and tmp for writing
    if (rep == NULL || tmp == NULL)
    {
        // if files could not be opened
        perror("\nError ");
    }
    else
    {
        char target[MAX_W];
        printf("\n Target : ");
        scanf("%500s", target);
        eat(); // gets target word
        char replace[MAX_W];
        printf("\n Replacement : ");
        scanf("%500[^\n]", replace);
        eat(); // gets its replacement
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
            remove("Temp.Ctt");
            perror("\nFailed ");
        }
        else
        {
            if (rename("Temp.Ctt", frep) == 0)
                printf("\nSucess.\n\nReplaced any instances of \"%s\" with \"%s\".\n", target, replace);
            else
            {
                remove(frep);
                if (rename("Temp.Ctt", frep) == 0)
                    printf("\nSucess.\n\nReplaced any instances of \"%s\" with \"%s\".\n", target, replace);
                else
                {
                    remove("Temp.Ctt");
                    perror("\nFailed ");
                }
            }
        }
    }
    return 0;
}
void eat()
{
    int eat;
    while ((eat = getchar()) != '\n' && eat != EOF)
        ;
}