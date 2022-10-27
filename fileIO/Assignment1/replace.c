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
    //     return 1;
    // }
    system("clear");
    //Traverse(argv[1]);
    //result = Srch(argv[1], argv[2]);
    Traverse();
    SrchAndReplace(argc,argv);
    return 0;
}
