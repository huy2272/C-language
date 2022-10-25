#include <stdio.h>
#include <stdlib.h>

int main(){
    //Writing a character into a txt file
    FILE *fp = NULL;
    // fp = fopen("program.txt", "w+");
    // for (int ch = 33; ch < 100; ch++)
    // {
    //     fputc(ch, fp);
    // }
    // fclose(fp);
    // fp = NULL;

    //Writing a string to a txt file
    //Make sure to add \n at the end of each string
    //Otherwise we will run into problem when reading the file again
    fp = fopen("program.txt", "w+");
    fputs("This is a string\n", fp);
    fputs("New string\n", fp);
    fclose(fp);
    fp = NULL;
    
    //Writing formatted output to a txt file
    // fp = fopen("program.txt", "w+");
    // fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 514);

    // fclose(fp);
    // fp = NULL;

    // int num;
    // FILE *fptr = NULL;
    // fptr = fopen ("program.txt", "w");
    // if(fptr == NULL){
    //     printf("Error!");
    //     exit(1);
    // }

    // printf("Enter num:");
    // scanf("%d", &num);
    // fprintf(fptr,"%d", num);
    // fclose(fptr);
    return 0;
}