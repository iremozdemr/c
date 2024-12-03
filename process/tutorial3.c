//3 fork varsa 8 defa hello yazılır
//4 fork varsa 16 defa hello yazılır

#include <stdio.h>
#include <unistd.h>

int main(){

    fork();
    fork();
    fork();
 
    printf("hello \n");

    return 0;
}