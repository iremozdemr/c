#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("olmayan_dosya.txt","r");

    if(file == NULL){
        printf("hata kodu: %d\n", errno);  
        perror("hata mesaji");  
    }

    return 0;
}