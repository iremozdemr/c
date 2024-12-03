#include <stdio.h>

struct mystruct1{
    int a;
    int b;
};

typedef struct mystruct2{
    int a;
    int b;
}mystruct2;

struct mystruct3{
    int a;
    int b;
};

typedef struct mystruct3 mystruct3;

int main(){
    struct mystruct1 variable1;

    struct mystruct2 variable2;
    mystruct2 variable3;

    struct mystruct3 variable4;
    mystruct3 variable5;
    
    return 0;
}