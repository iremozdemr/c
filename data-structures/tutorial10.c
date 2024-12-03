#include <stdio.h>

struct outer{
    int member1;

    struct inner{
        int a;
        int b;
    }member2;
};
//iç içe nested structure'lar

struct child{
    int a;
};

struct parent{
    int x;
    struct child member1;
    struct child member2;
};
//ayrı nested structure'lar
//child parent'in içindedir
//bu yüzden parent tanımlanmadan önce
//child tanımlanmalıdır

int main(){
    return 0;
}