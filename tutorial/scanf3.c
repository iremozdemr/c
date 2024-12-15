#include <stdio.h>

int main(){
    char string[128];
    printf("enter a string: ");
    scanf("%[^a]",string);
    printf("you entered: %s \n",string);
    //^ işaretinden sonra gelen harf okunduğunda
    //okumayı bırakır

    return 0;
}