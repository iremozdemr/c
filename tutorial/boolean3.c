#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(){
    bool x = true;
    bool y = false;

    printf("true: %d \n",x);
    printf("false: %d \n",y);

    return 0;
}