#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

int Report(int hits, char *fname, const char *str){
    FILE *fpf = NULL;
    int updates = hits;
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    if (strcmp(cwd,"/home/huy/C-language/COMP348-A1") == 0)
    {
        if (access("report.ctt", F_OK) == 0){
            //The report file already exist
            fpf = fopen("report.ctt", "a");
            strcat(cwd, "/");
            fprintf(fpf, "%d              %s\n", updates, strcat(cwd,fname));
            fclose(fpf);
            fpf = NULL;
        }
        if (access("report.ctt", F_OK) != 0){
            //If there 0 it means false, so create a file
            fpf = fopen("report.ctt", "w+");
            fprintf(fpf, "Target string: %s\n", str);
            fprintf(fpf, "Search begins in current folder: %s\n", cwd);
            fputs("** Search Report **\n", fpf);
            fputs("Updates         File Name\n", fpf);
            strcat(cwd, "/");
            fprintf(fpf, "%d              %s\n", updates, strcat(cwd,fname));
            fclose(fpf);
            fpf = NULL;
        }
    }
    return 0;
}