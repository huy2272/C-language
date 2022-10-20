#include <stdio.h>
#include <stdlib.h>

#define FILENAME "apple.txt"

int main()
{
    FILE *fp = NULL;
    char ch;
    int count = 0;

    //Open the file
    fp = fopen(FILENAME, "r");
    if (fp == NULL)
        return -1;
    while ((ch=fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            count++;
    }
    
    fclose(fp);
    fp = NULL;
    printf("Total number of lines are %d\n", ++count);

    return 0;
}
