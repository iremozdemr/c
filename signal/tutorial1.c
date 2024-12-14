//sinyal gönerimi:
//process -> process
//os kernel -> process
//user -> process

//sinyal:
//asenkron
//değere ve isme sahiptir

//SIGABRT:
//programın anormal bir şekilde sonlandığını belirtir
//abort() fonksiyonu çağrıldığında bu sinyal gönderilir

//SIGFPE:
//yanlış bir aritmetik işlem yapıldığında
//sıfıra bölme

//SIGILL:
//geçersiz bir komutun çalıştırıldığını belirtir

//SIGINT:
//process'i sonlandırır
//klavyeden gönderilir

//SIGTERM
//process'i sonlandırır
//process'i düzgün bir şekilde sonlandırır

//SIGKILL
//process'i sonlandırır
//process'i zorla sonlandırır

//SIGSEGV
//process'i sonlandırır
//bellek segmentasyonu hatası

//SIGALRM
//process'i sonlandırır
//zamanlayıcı alarm sinyali

//SIGHUP
//process'i sonlandırır
//terminal kapanışı
//bağlantı kaybı

//SIGCHLD
//yoksayılır
//child process'lerin durumu değiştiğinde gönderilir

//SIGSTOP
//process'i duraklatır

//SIGCONT
//process'i devam ettirir

//kill:
//process'e sinyal göndermek için kullanılır
//0 dönerse sinyal başarıyla gönderilmiştir

//int kill(pid_t pid,int sig)
//pid: hangi process'e sinyal gönderileceğini belirtir
//pid > 0 belirtilen pid'ye sahip process'e sinyal gönderilir
//pid = 0 aynı process group içinde bulunan tüm process'lere sinyal gönderilir
//pid = -1 tüm process'lere sinyal gönderilir
//sig: gönderilecek sinyal türü

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); 
    //current process'in pid'si
    printf("current process pid: %d\n", pid);

    printf("sending SIGTERM\n");
    kill(pid, SIGTERM);

    printf("this will not be printed\n");
    //bu satır çalışmayacak çünkü SIGTERM süreci sonlandırır

    return 0;
}