#include <stdio.h>
#include <stdlib.h> 
#define FILENAME "apple.txt"
int main(){
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char ch = ' ';
    fp = fopen(FILENAME, "r");
    if (fp == NULL)
        return -1;
    
    //Create a temp file if it does not exist and write to it
    fp1 = fopen("temp.txt", "w");
    if (fp1 == NULL)
        return -1;
    
    while ((ch = fgetc(fp)) != EOF)
    {
        if (islower(ch))
        {
            //Convert to capital letter
            ch = ch-32;
        }
        
        fputc(ch, fp1);
    }
    fclose(fp);
    fclose(fp1);

    //Rename
    rename("temp.txt", FILENAME);

    //remove the temp file
    remove("temp.txt");

    //print out the content
    fp = fopen(FILENAME, "r");

    if ((fp == NULL))
        return -1;
    
    while ((ch = fgetc(fp)) != EOF)
        printf("%c",ch);
    
    fclose(fp);
    fp = NULL;
    fp1 = NULL;   

    return 0;
}