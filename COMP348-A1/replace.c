#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Please make sure to enter one string\n");
        return 1;
    }
    system("clear");
    Traverse(argv[1]);

    //Read the report.ctt file
    FILE *fp;
    char str[61];
    fp = fopen("report.ctt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return(-1);
    }
    
    while (fgets(str,60,fp) != NULL)
        printf("%s", str);

    fclose(fp);
    fp = NULL;
    return 0;
}
