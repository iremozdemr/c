#include <stdio.h>

int main(){
    char string[128];
    printf("enter a string: ");
    scanf("%[^\n]",string);
    printf("you entered: %s \n",string);
    //yeni satıra geçildiğinde
    //okumayı bırakır

    return 0;
}