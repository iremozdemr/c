//sprintf():
//string'e variable yazar

//sscanf():
//string'den variable alır

#include <stdio.h>

int main(){
    //sprintf() kullanımı:

    char string1[100];
    int num = 10;

    int result1 = sprintf(string1,"the integer is: %d",num);
    printf("%s \n",string1);

    printf("result: %d \n",result1);

    //sscanf() kullanımı:

    char string2[100] = "the integer is: 20";
    int number;

    int result2 = sscanf(string2,"the integer is: %d",&number);
    printf("%d \n",number);

    printf("result: %d \n",result2);

    return 0;
}