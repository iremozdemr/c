//exec:
//parent process bitmez
//yürütülmekte olan kod yeni bir programla değiştirilir
//yeni program current process'in pid'sini miras alır
//exec çağrıldıktan sonra eski koddan hiçbir şey çalıştırılmaz

//başarılı olursa exec fonksiyonu return yapmaz 
//hata durumunda -1 döner

//exec fonksiyonları:
//execl
//execv
//execle
//execve

//int execv(const char *path,char *const argv[])
//path: çalıştırılacak yeni programın path'i
//argv: yeni programa geçirilecek komut satırı argümanları
//argv'de ilk arguman genellikle çalıştırılacak programın adı olur
//argv'de son arguman null olmalıdır

#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"/bin/ls", "-l", NULL}; 
    //argümanlar dizisi

    printf("before execv\n");

    execv(args[0], args); 
    // ls -l komutunu çalıştır
    
    perror("execv failed");
    return 1;
}