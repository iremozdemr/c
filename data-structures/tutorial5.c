#include <stdio.h>
#include <string.h>

struct outer{
    int outer_element1;
    int outer_element2;

    struct inner{
        int x;
        int y;
    }outer_element3;
};
//outer_element3 inner'dan oluşmuştur
//outer_element3 outer'ın elementidir

int main(){
    struct outer mystruct;

    mystruct.outer_element1 = 12;
    mystruct.outer_element2 = 15;
    mystruct.outer_element3.x = 4;
    mystruct.outer_element3.y = 5;

    struct outer *pointer;
    pointer = &mystruct;
    pointer -> outer_element1 = 13;

    return 0;
}