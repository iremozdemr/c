//R_OK : okuma izni
//W_OK : yazma izni
//X_OK : çalıştırma izni
//F_OK : dosyanın varlığı

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
    if (access("olmayan_dosya.txt", R_OK) == -1) {
        printf("hata kodu: %d \n", errno);  
        printf("hata mesaji: %s \n",strerror(errno));
        perror("hata mesaji");         
    }

    return 0;
}