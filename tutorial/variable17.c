#include <stdio.h>
#include <string.h>

int main(){

    char word1[] = "hello";
    char word2[11] = "hello world";
    char word3[] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'};
    char word4[50] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd','\0'};
    //en sona \0 eklenir

    int size1 = strlen(word3);
    printf("%d\n",size1);
    //strlen ile uzunluk bulunurken sondaki \0 dahil edilmez

    int size2 = sizeof(word3);
    printf("%d\n",size2);
    //sizeof ile uzunluk bulunurken sondaki \0 dahil edilir

    int size3 = strlen(word4);
    printf("%d\n",size3);
    //sonuc 11 olur

    int size4 = sizeof(word4);
    printf("%d\n",size4);
    //sonuc 50 olur
    
    return 0;
}