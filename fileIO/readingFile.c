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

    //Reading a string
    //We need to allocate memory space for this pointer
    char str[61];
    fp = fopen("apple.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return(-1);
    }
    
    while (fgets(str,60,fp) != NULL)
    {
        printf("%s", str);
    }
    fclose(fp);
    fp = NULL;

    //Reading formatted input from a file
    fp = fopen("apple.txt", "r");
    char str1[10], str2[10], str3[10];
    fscanf(fp, "%s %s %s", str1, str2, str3);
    printf("\nstr1: |%s|\n", str1);
    printf("str2: |%s|\n", str2);
    printf("str3: |%s|\n", str3);
    fclose(fp);
    fp = NULL;

    return 0;
}