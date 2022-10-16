#include <stdio.h>
#define YEARS_OLD 22
#ifndef YEARS_OLD
#define YEARS_OLD 10
#endif
int main(){
    printf("Hello my name is Huy, and I am %d\n", YEARS_OLD);
    char str[100];
    int i;
    //Reading input
    printf("Enter your name and age:\n");
    scanf("%s%d",str,&i);
    printf("You have entered: My name is %s and I am %d", str, i);
    return 0;
}