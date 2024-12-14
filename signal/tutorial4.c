//pause:
//bir sinyal alınana kadar process'i askıya alır
//gelen sinyal process'i sonlandırıyorsa hiçbir şey dönmez
//gelen sinyal signal handler tarafından yakalanıyorsa -1 döner

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("received SIGINT (signal: %d) \n", sig);
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("waiting for SIGINT (press ctrl+c)\n");

    pause();

    printf("process exiting after signal\n");
    
    return 0;
}