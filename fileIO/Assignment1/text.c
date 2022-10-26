#include <stdio.h>
#include <string.h>
#include "methods.h"

int Srch(char *fname, char *str){
    FILE *fp, *fp1;
    int line_num = 1;
    int hits = 0;
    char buffer[513];
    fp = fopen(fname,"r");
    char ch;
    if (fp == NULL)
    {
        printf("Error finding file");
        return -1;
    }
    
    //Create a temporary file to turn the targeted string into upper case letters
    fp1 = fopen("temporaryFile.txt", "w");
    
    if (fp1 == NULL)
    {
        return -1;
    }
    
    while ((fgets(buffer, 512, fp)) != NULL)
    {
        if ((strstr(buffer, str)) != NULL)
        {
            printf("There's a match on line: %d\n", line_num);
            printf("%s\n", buffer);
            hits++;
        }
        line_num++;   
    }

    if (hits == 0)
    {
        printf("No matches found in this file");
    }else{
        printf("Number of hits: %d\n", hits);
    }

    
    fclose(fp);
    fclose(fp1);
    fp = NULL;
    fp1 = NULL;
    // Report(hits, fname, str);
    
    return 0;
}