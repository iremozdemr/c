#include <stdio.h>
#include <unistd.h>

int main(){
    printf("hello \n");
    
    fork();

    printf("world \n");

    return 0;
}