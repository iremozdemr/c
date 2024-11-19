#include <stdio.h>

int main(){

    for (int a = 0 ; a < 5 ; a++) {
        printf("%d \n", a);
    }

    int b = 0;
    for (; b < 5 ; b++) {
        printf("%d \n", b);
    }

    int c = 0;
    for (; c < 5 ;) {
        printf("%d \n", c);
        c++;
    }

    return 0;
}