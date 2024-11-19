// strlen	string uzunluğunu verir
// strcpy	stringi başka bir stringe kopyalar
// strcat	iki stringi birleştirir
// strcmp	iki stringi karşılaştırır
// strncpy	belirli sayıda karakteri kopyalar
// strncat	belirli sayıda karakteri birleştirir
// strncmp	belirli sayıda karakteri karşılaştırır
// strchr	bir stringde bir karakter arar
// strstr	bir stringde bir alt string arar
// strtok	stringi parçalara böler
// memcpy	bellekten belleğe kopyalar
// memset   belleği bir değerle doldurur

#include <stdio.h>
#include <string.h>

int main(){

    char word[] = "hello";
    strcpy(word,"abcde");
    printf("%s\n",word);
    //stringleri degistirmek icin kullanilan method

    char str1[] = "hello";
    char str2[] = "world";
    strcpy(str1,str2);
    printf("%s\n",str1);
    printf("%s\n",str2);
    //str2'yi str1'e kopyalar
    //str1 degisir
    //stringleri kopyalamak icin kullanilan method

    char str3[20] = "hello";
    char str4[] = "world";
    strcat(str3,str4);
    printf("%s\n",str3);
    printf("%s\n",str4);
    //str4'ü str3'e ekler
    //sonuc str3'de depolanır
    //stringleri birlestirmek icin kullanilan method

    char str5[] = "hello";
    char str6[] = "hello";
    char str7[] = "hi";
    printf("%d\n", strcmp(str5, str6));
    printf("%d\n", strcmp(str5, str7));
    //stringleri alfabetik olarak karsilastirmak icin kullanilan method

    char str8[20] = "hiiiiiiii";
    char str9[20] = "world";
    strncpy(str8,str9,3);
    printf("%s\n",str8);
    printf("%s\n",str9);

    char str10[20] = "hello";
    char str11[20] = "world";
    strncat(str10,str11,3);
    printf("%s\n",str10);
    printf("%s\n",str11);

    char mystr1[] = "hell";
    char mystr2[] = "helloo";

    int result = strncmp(str1, str2, 3);  
    if(result == 0){
        printf("ilk 3 karakter esit\n");
    } 
    else{
        printf("ilk 3 karakter esit degil\n");
    }

    return 0;
}