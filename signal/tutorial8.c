//signal:
//önceki signal handler'ı döner

//sighandler_t signal(int signum, sighandler_t handler)
//signum: 
//yakalanacak sinyalin numarası 
//yakalanacak sinyalin ismi
//SIGKILL olmamalıdır
//SIGSTOP olmamalıdır
//handler:
//bir fonksiyona işaret eden pointer
//user defined olabilir
//önceden tanımlanmış olabilir (SIG_DFL,SIG_IGN)

//signal handler:
//return type void olmalıdır
//tek bir parametre almalıdır
//bu parametre int olmalıdır

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handle_sigint(int sig) {
    printf("caught signal %d\n", sig);
}

int main() {
    signal(SIGINT,signal_handle_sigint);

    while (1) {
        printf("hello world \n");
        sleep(1);
    }

    return 0;
}