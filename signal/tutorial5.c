//her process kendisine gelen sinyalleri kontrol etmek için bir signal mask kullanır
//signal mask hangi sinyallerin bloke edileceğini belirler

//eğer bir sinyal bloke edilmişse:
//sinyal pending signals setine eklenir
//signal mask bu sinyali bloke etmeyi bıraktığında sinyal devam eder

//sigprocmask:
//bir process'in signal mask'ini değiştirmek için kullanılır
//sinyalleri bloke edebilir
//sinyallerdeki blokeyi kaldırabilir
//yeni bir signal mask ayarlayabilir

//int sigprocmask(int how,const sigset_t *set,sigset_t *oldset)
//how:
//yeni signal mask'in nasıl uygulanacağını belirtir
//SIGBLOCK
//SIG_UNBLOCK
//SIG_SETMASK
//set:
//yeni signal mask'i belirler
//oldset:
//önceki signal mask'i saklar

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("caught signal %d\n", sig);
}

int main() {
    sigset_t block_set;
    sigset_t old_set;

    sigemptyset(&block_set);
    //sinyal set'i başlat
    sigaddset(&block_set, SIGINT); 
    //SIGINT'i bloke et

    signal(SIGINT, handle_signal);

    printf("blocking SIGINT...\n");
    sigprocmask(SIG_BLOCK, &block_set, &old_set);
    //SIGINT'i bloke et

    printf("SIGINT is blocked try pressing ctrl+c...\n");
    sleep(5);
    //5 saniye boyunca sinyalleri bloke et

    printf("unblocking SIGINT...\n");
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    //SIGINT'i bloklamayı kaldır

    printf("SIGINT is unblocked try pressing ctrl+c again...\n");
    sleep(5);
    //5 saniye daha bekle

    return 0;
}