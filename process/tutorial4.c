#include <stdio.h>
#include <unistd.h>

int main(){

    int x = 0;

    printf("%d\n",++x);

    fork();

    printf("%d\n",++x);

    fork();

    printf("%d\n",++x);

    return 0;
}

//sonuç:
//1
//2
//2
//3
//3
//3
//3