//sigaction:
//signal fonksiyonuna benzer

//signal fonksiyonunda:
//bir sinyal yakalandıktan sonra varsayılan sinyal davranışı tekrar ayarlanır

//sigaction fonksiyonunda:
//bir sinyal yakalandıktan sonra tekrar ayarlama gerektirmez

//int sigaction(int signum,const struct sigaction *act,struct sigaction *oldact)
//signum:
//ayarlanmak istenilen sinyalin numarası
//act:
//yeni sinyal işleyicisi
//oldact:
//eski sinyal işleyicisi

// struct sigaction {
//     void (*sa_handler)(int);      
//     //sinyal işleyici
//     void (*sa_sigaction)(int, siginfo_t *, void *); 
//     //gelişmiş kullanım için
//     sigset_t sa_mask;             
//     //sinyal işleyici çalışırken bloklanacak sinyaller
//     int sa_flags;                 
//     //işleyicinin davranışını değiştiren flag'ler 
// };

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("caught SIGINT (signal: %d)\n", sig);
}
//sinyal işleyici

int main() {
    struct sigaction act;

    act.sa_handler = handle_sigint;      
    sigemptyset(&act.sa_mask);           
    act.sa_flags = SA_RESTART;           

    sigaction(SIGINT, &act, NULL);

    printf("waiting for SIGINT (press ctrl+c)...\n");

    while (1) {
        sleep(1); 
    }

    return 0;
}