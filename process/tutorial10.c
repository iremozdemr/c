#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("program is starting...\n");
    
    if(1){
        printf("an error occurred exiting...\n");
        exit(1); 
    }

    printf("this line will not be executed\n");
    return 0;
}