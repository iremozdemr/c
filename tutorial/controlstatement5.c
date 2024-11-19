#include <stdio.h>

int main(){

    int charCount = 0;
    int lineCount = 0;
    int mychar;

    printf("enter a character\n");
    printf("press Ctrl+D / Ctrl+Z to exit:\n");

    while ((mychar = getchar()) != EOF) {

        charCount++;

        if(mychar == '\n'){
            lineCount++;
        }
    }

    printf("number of chars %d \n",charCount);
    printf("number of lines %d \n",lineCount);

    return 0;
}