#include <stdio.h>

struct mystruct1{
    int a;
    int b;
}variable1;

int main(){
    struct mystruct2{
        int a;
        int b;
    }variable2;

    struct mystruct2 variable3;

    variable1.a = 1;
    variable1.b = 2;

    variable2.a = 1;
    variable2.b = 2;

    variable3.a = 1;
    variable3.b = 2;

    return 0;
}