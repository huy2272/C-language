#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Please make sure to enter one string\n");
        return 0;
    }
    
    int strSize = 0;
    char *strUser;

    //Find out the length of user's input string
    strSize += strlen(argv[1]);
    //Allocate memory for user's input string
    strUser = malloc(strSize);
    strcat(strUser, argv[1]);
    printf("cmmd string is: %s\n", strUser); 
    return 0;
}
