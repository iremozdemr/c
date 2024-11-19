#include <stdio.h>

int main() {
    
    char string[] = "hello";
    
    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
    }
    
    return 0;
}