#include <stdio.h>
#include <unistd.h>
#include <limits.h>
void Report(int hits, char *fname, char *str){
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("Target string: %s\n", str);
    printf("Search begins in current folder: %s\n", cwd);
    printf("** Search Report **\n");
    printf("Updates         File Name\n");
    printf("%d              %s\n", hits, fname);
}