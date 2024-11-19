#include <stdio.h>
#include <stdbool.h>

int main(){

    _Bool a1 = -5;
    _Bool b1 = 0;

    printf("true: %d \n",a1);
    printf("false: %d \n",b1);

    bool a2 = -5;
    bool b2 = 0;

    printf("true: %d \n",a2);
    printf("false: %d \n",b2);

    return 0;
}