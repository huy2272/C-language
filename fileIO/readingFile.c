#include <stdio.h>

int main(){
    FILE *fp;
    int c;
    fp = fopen("program.txt", "r");

    if (fp == NULL)
    {
        perror("There is an error in opening the file");
        return(-1);
    }
    
    //Reading a single character
    while ((c = fgetc(fp)) != EOF)
    {
        printf("Cotent: %c\n", c);
    }
    fclose(fp);
    fp = NULL;
    return 0;
}