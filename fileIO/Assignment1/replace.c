#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "methods.h"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Please make sure to enter one string\n");
        return 1;
    }
    system("clear");
    Traverse(argv[1]);
    return 0;
}
