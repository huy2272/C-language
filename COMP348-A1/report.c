#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>

int Report(int hits, char *fname, const char *str){
    FILE *fp = NULL;
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    if (hits == 0)
    {
        return 0;
    }
    
    if (access("report.ctt", F_OK) == 0)
    {
        //The report file already exist
        fp = fopen("report.ctt", "a");
    }else{
        //Create the file
        fp = fopen("report.ctt", "w+");
    }
    
    
    if (fp == NULL)
    {
        printf("Error cannot write to file");
        return 1;
    }
    
    fprintf(fp, "Target string: %s\n", str);
    fprintf(fp, "Search begins in current folder: %s\n", cwd);
    fputs("** Search Report **\n", fp);
    fputs("Updates         File Name\n", fp);
    fprintf(fp, "%d              %s\n", hits, cwd);
    fclose(fp);
    fp = NULL;
    return 0;
}