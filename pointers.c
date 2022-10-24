#include <stdio.h>
#include <stdlib.h>
int main(){
    int n = 5;
    int array_static[5] = {1,2,3,4,5};
    //Dynamically assign array size using malloc cmd
    int *array_dynamic = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        array_dynamic[i] = i;
    }
    //Accessing using index
    printf("Array_static array_static[2]: %d\n", array_static[2]);
    printf("Array_static array_dynamic[0]: %d\n", array_dynamic[0]);
    //Accessing using pointers
    printf("Array_static array_static[3]: %d\n", *(array_static + 3));
    printf("array_dynamic[1]: %d\n",*(array_dynamic + 1));
    return 0;
}