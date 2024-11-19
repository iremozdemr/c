#include <stdio.h>
#include <stdbool.h>

int main(){
    bool a1 = true;
    bool b1 = false;

    printf("true: %d \n",a1);
    printf("false: %d \n",b1);

    printf("true: %i \n",a1);
    printf("false: %i \n",b1);

    _Bool a2 = true;
    _Bool b2 = false;

    printf("true: %d \n",a2);
    printf("false: %d \n",b2);

    printf("true: %i \n",a2);
    printf("false: %i \n",b2);

    return 0;
}

//false:
//0 ile gösterilir

//true:
//0 dışında herhangi bir sayıyla gösterilir