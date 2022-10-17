#include <stdio.h>
//Include this to use bool instead of _Boo
//This header file also allow use to assign true/false, instead of 1 or 0
#include <stdbool.h>

int main(){
    float a = 3.00f;
    //If we do not add the f after the number, the compiler will intepret it as a double
    double b = 3.00;
    _Bool c = 1;
    bool d = true;
    //Below are all integers, they are just modified with short, long, unsigned modifiers
    short i = 12;
    //short int i = 12;
    long ii = 1200000;
    //long int ii = 1200000;
    unsigned u = 12;
    //unsigned int u = 12;
    long long iiii = 1200000L;

}