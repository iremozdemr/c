#include <stdio.h>

enum bool{true,false};

int main(){
    enum bool value1 = true;
    enum bool value2 = false;

    printf("true: %d \n",value1);
    printf("false: %d \n",value2);

    return 0;
}