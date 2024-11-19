//eof <stdio.h> kütüphanesinde tanımlıdır
//dosyanın sonuna gelindiğini belirtir
//input alma işleminin bittiğini belirtir

#include <stdio.h>

int main(){
    
    int mychar;
    
    printf("enter a character\n");
    printf("press Ctrl+D / Ctrl+Z to exit:\n");

    while ((mychar = getchar()) != EOF) {
        putchar(mychar); 
    }

    printf("eof detected \n");
    printf("exiting the program \n");

    return 0;
}