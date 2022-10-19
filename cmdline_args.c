#include <stdio.h>

//int argc will be a.out, the second arguement will be an arr of strings
int main(int argc, char* argv[]){
    int num = argc;
    printf("Number of args: %d\n", num);
    for (int i = 0; i<argc;i++){
        printf("%s\n",argv[i]);
    }
    //fprintf allows us to define where the output will go
    //fprintf(stderr, "stderr\n");
    return 0;
    //By doing ./a.out abcd 2> err.txt
    //2 stands for stderr, which will be push into an err.txt file
    //To view the text file we use cat err.txt

    //stderr (fprintf) stream is not buffered but it will be slower 
    //While stdout (printf) and stdin is buffered but it will be faster
}