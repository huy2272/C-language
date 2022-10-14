#include <stdio.h>
#define YEARS_OLD 22
#ifndef YEARS_OLD
#define YEARS_OLD 10
#endif
int main(){
    printf("Hello my name is Huy, and I am %d\n", YEARS_OLD);
    //Comments
    return 0;
}