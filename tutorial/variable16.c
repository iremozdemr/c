#include <stdio.h>

int main() {
    char mychar;
    
    printf("bir satir girin:");
    
    while ((mychar = getchar()) != '\n') { 
        putchar(mychar); 
    }

    putchar('\n');

    return 0;
}