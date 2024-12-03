#include <stdio.h>
#include <unistd.h>

int main(){
    printf("hello ");
    
    fork();

    printf("world \n");

    return 0;
}