#include <stdio.h>

int main(){

    int number = 25;

    if((number = 100)){
        printf("true \n");
    }
    else{
        printf("false \n");
    }

    if(number == 50){
        printf("true \n");
    }
    else{
        printf("false \n");
    }

    int x = 1;
    int y = 2;
    int z = 3;

    x = (y = z--);

    printf("x: %d \n",x);
    printf("y: %d \n",y);
    printf("z: %d \n",z);

    int a = 1;
    int b = 2;
    int c = 3;

    a = b = ++c;

    printf("a: %d \n",a);
    printf("b: %d \n",b);
    printf("c: %d \n",c);

    return 0;
}