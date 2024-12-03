//structure

//array farklı türden variable içeremez
//structure farklı türden variable içerebilir

//structure içinde function bulunamaz
//structure içinde constructor bulunamaz
//structure içinde static variable bulunamaz

#include <stdio.h>

int main(){
    struct mystruct1{
        int a;
        int b;
    };
    struct mystruct1 s1;

    struct mystruct2{
        int x;
        int y;
    }s2;

    printf("%lu\n",sizeof(s1));
    printf("%lu\n",sizeof(s2));

    printf("%lu\n",sizeof(struct mystruct1));
    printf("%lu\n",sizeof(struct mystruct2));

    //printf("%lu\n",sizeof(struct));
    
    return 0;
}