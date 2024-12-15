#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handle(int sig) {
    printf("caught signal %d\n", sig);

    alarm(5);
}

void timer_handle(int sig) {
    if(sig == SIGALRM){
        printf("5 seconds passed exiting");
        exit(13);
    }
}

int main() {
    signal(SIGINT,signal_handle);
    signal(SIGTSTP,signal_handle);
    signal(SIGALRM,timer_handle);

    alarm(5);

    while (1) {
        pause(); 
    }

    return 0;
}