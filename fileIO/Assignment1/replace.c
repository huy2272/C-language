#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int strSize = 0;
    strSize += strlen(argv[1]);
    printf("strSize = %d\n", strSize);
    char *strUser;
    strUser = malloc(strSize);
    strcat(strUser, argv[1]);
    printf("cmmd string is: %s\n", strUser); 
    return 0;
}
