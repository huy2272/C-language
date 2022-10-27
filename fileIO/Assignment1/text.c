#include <stdio.h>
#include <string.h>
#include "methods.h"

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