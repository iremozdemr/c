#include <stdio.h>

int main() {

    char mychar;

    printf("bir karakter girin: ");
    mychar = getchar(); 
    //kullanıcıdan bir karakter alır

    printf("girdiğiniz karakter: ");
    putchar(mychar);    
    //kullanıcıdan alınan karakteri ekrana yazar

    putchar('\n');
    
    return 0;
}