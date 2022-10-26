#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int Traverse(){
    struct dirent *entry;
    struct stat filestat;
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        printf("Could not open current directory");
        return 0;
    }
    
    
    while ((entry = readdir(dir)) != NULL){
        stat(entry->d_name,&filestat);
        if (S_ISDIR(filestat.st_mode))
            printf("Directory: %s\n", entry->d_name);
        else
            printf("File: %s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}