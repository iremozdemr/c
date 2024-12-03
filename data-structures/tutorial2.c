#include <stdio.h>

int main(){
    struct struct1{
        int x1;
        int y1;
    };
    struct struct1 mystruct = {10,11};
    //doğru

    /*
    struct struct2{
        int x2 = 0;
        int y2 = 0;
    };
    */
    // yanlış
    return 0;
}