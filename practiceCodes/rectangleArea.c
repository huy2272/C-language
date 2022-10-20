#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    // atoi converts character string to integer value
    // int width = atoi(argv[1]);
    // int height =  atoi(argv[2]);

    // atoi converts character string to double value
    double width = atof(argv[1]);
    double height =  atof(argv[2]);
    double area = width*height;
    double perimeter = 2*(width + height);

    printf("Area is: %lf\n",area);
    printf("Perimeter is: %lf\n",perimeter);
    return 0;
}