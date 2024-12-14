#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); 
    //current process'in pid'si
    printf("current process pid: %d\n", pid);

    printf("sending SIGINT\n");
    kill(pid, SIGINT);

    printf("this will not be printed\n");

    return 0;
}