#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"

int main(int argc, char *argv[])
{
    int result;
    // if (argc != 2)
    // {
    //     printf("Please make sure to enter one string\n");
    //     return 0;
    // }
    system("clear");
    CurrFile(argv[1]);
    result = Srch(argv[1], argv[2]);
    return 0;
}
