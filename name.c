#include <stdio.h>
#define YEARS_OLD 22
#ifndef YEARS_OLD
#define YEARS_OLD 10
#endif
int main(){
    printf("Hello my name is Huy, and I am %d\n", YEARS_OLD);
    char str[100];
    int i;
    double dbl; //Double the precision compared to float use %lf for scanf to read a double from user input
    //Reading input
    printf("Enter your name and age:\n");
    scanf("%s%d",str,&i);
    printf("You have entered: My name is %s and I am %d", str, i);
    return 0;
}