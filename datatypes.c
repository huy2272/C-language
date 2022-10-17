#include <stdio.h>
//Include this to use bool instead of _Boo
//This header file also allow use to assign true/false, instead of 1 or 0
#include <stdbool.h>

int main(){

    //Basic data types
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
    //unsigned int only store non-negative numbers
    //unsigned int u = 12;
    long long iiii = 1200000L;

    //User defined variable
    enum myColor {
        red,
        yellow,
        blue
    };
    enum myColor primaryColor, favColor;
    primaryColor = red;
    favColor = blue;
    //These variables are treated as integer constants
    //So red = 0, yellow = 1, blue = 2 
    if (primaryColor == 0)
    {
        //This will print
        printf("True\n");
    }
    //We can also assign specific integer value to enum identifiers

    enum dir {
        north,
        east,
        west,
        south = 10
    };
    enum dir myDir = south;
    if (south == 10)
    {
        //This will print since we assign a specific value to south
        printf("Enum");
    }
    
    char celsius;
    celsius = 'C'; 
    //Use a single quote, double quote = string
    //We can assign integer values, compiler will intepret as ASCII value

    //We can assign escape characters to char as well
    char escape = '\n';


}