#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void helper(DIR *, struct dirent *, struct stat, char *, int);
void dircheck(DIR *, struct dirent *, struct stat, char *, int);

int Traverse(){
  DIR *dp;
  struct dirent *dir;
  struct stat buffer;
  char currentPath[FILENAME_MAX] = ".";
  int depth = 0; //Keeps track of how many subdirectories we have entered

  /*Open Current Directory*/
  if ((dp = opendir(".")) == NULL)
    return 1;

  /*Store Current Working Directory in currentPath*/
  if ((getcwd(currentPath, FILENAME_MAX)) == NULL)
    return 1;

  /*Read all items in directory*/
  while ((dir = readdir(dp)) != NULL)
  {

    // Ignore parent and current directory
    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
      continue;

    // Gets the current path
    getcwd(currentPath, FILENAME_MAX);
    strcat(currentPath, "/");
    // Append the subdirectory found to the current path
    strcat(currentPath, dir->d_name);
    if (stat(currentPath, &buffer) == -1)
    {
      perror("stat");
      return 1;
    }
    getcwd(currentPath, FILENAME_MAX);

    // Checks if current item is a file
    if (S_ISREG(buffer.st_mode))
      printf("%s\n", dir->d_name);

    // Checks if current item is a directory
    if (S_ISDIR(buffer.st_mode))
      dircheck(dp, dir, buffer, currentPath, depth);
  }
  closedir(dp);
  return 0;
}

/*Recursively called helper function*/
void helper(DIR *dp, struct dirent *dir, struct stat buffer,
            char currentPath[FILENAME_MAX], int depth)
{
  int i = 0;

  if ((dp = opendir(currentPath)) == NULL)
    printf("Error: Failed to open Directory ==> %s\n", currentPath);

  while ((dir = readdir(dp)) != NULL)
  {

    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
      continue;

    strcat(currentPath, "/");
    strcat(currentPath, dir->d_name);
    stat(currentPath, &buffer);
    getcwd(currentPath, FILENAME_MAX);

    if (S_ISREG(buffer.st_mode))
    {
      for (i = 0; i < depth; i++)
        printf("    ");
      printf("%s/%s\n", currentPath, dir->d_name);
    }

    if (S_ISDIR(buffer.st_mode))
      dircheck(dp, dir, buffer, currentPath, depth);
  }
  
  //Cleanup
  chdir("..");
  closedir(dp);
}

void dircheck(DIR *dp, struct dirent *dir, struct stat buffer,
              char currentPath[FILENAME_MAX], int depth)
{
  int i = 0;
  strcat(currentPath, "/");
  strcat(currentPath, dir->d_name);

  for (i = 0; i < depth; i++)
    printf("    ");
  printf("%s (subdirectory)\n", dir->d_name);
  chdir(currentPath);
  depth++;
  //Call this function again recursively until there are no more subdirectory
  helper(dp, dir, buffer, currentPath, depth);
}