#include <stdio.h>
#include <string.h>

int main(){
    //degisken isimleri rakamla baslayamaz
    //degisken isimleri sadece
    //-rakam
    //-harf
    //-underscore
    //icerebilir

    int x=5, y=6, z=7;
    printf("%d %d %d \n",x,y,z);

    int a,b,c;
    a = b = c = 50;
    printf("%d %d %d \n",a,b,c);

    int number = 5;
    float floatNumber = 2.5;
    double doubleNumber = 2.3;
    char character = 'x';

    int sizeOfInt = sizeof(int);
    //4
    int sizeOfChar = sizeof(char);
    //1
    int sizeOfFloat = sizeof(float);
    //4
    int sizeOfDouble = sizeof(double);
    //8
    
    printf("the size of int data type: %d \n",sizeOfInt);
    printf("the size of char data type: %d \n",sizeOfChar);
    printf("the size of float data type: %d \n",sizeOfFloat);
    printf("the size of double data type: %d \n",sizeOfDouble);

    return 0;
}