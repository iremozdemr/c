#include <stdio.h>

int main(){
    char string[128];
    printf("enter a string: ");
    scanf("%[A-Z]",string);
    //sadece büyük harfli karakterler alınır
    //küçük harfe gelindiğinde okuma işlemi biter
    printf("you entered: %s \n",string);

    return 0;
}

//scanf("%[A-Z]",string);
//scanf("%[A-Z]s",string);
//ikisi de aynı