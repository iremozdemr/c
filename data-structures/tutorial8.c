#include <stdio.h>

struct mystruct{
    int a;
    int b;
};

int main(){
    struct mystruct struct1;
    struct1.a = 1;
    struct1.b = 2;

    struct mystruct struct2 = {1,2};

    struct mystruct struct3 = {.a = 1,.b = 2};
    
    return 0;
}