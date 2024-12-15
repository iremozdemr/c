#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void signal_handle(int sig) {
    if(sig == SIGINT){
        printf("CAUGHT sigint %d\n", sig);
        kill(0,SIGTERM);
    }
    else if(sig == SIGTERM){
        printf("CAUGHT sigterm %d\n", sig);
    }
}

int main() {
    pid_t children[5]; 

    for(int i=0; i<5; i++){
        pid_t pid = fork();

        if(pid == 0){
            printf("child %d running (pid: %d)\n", i, getpid());
            while(1){
                sleep(1);
            }
            exit(0);
        }
        else if(pid < 0){
            perror("fork failed");
            return 1;
        }
        else{
            children[i] = pid;
        }
    }

    signal(SIGINT,signal_handle);
    signal(SIGTERM,signal_handle);

    int active_children = 5; 

    while (active_children > 0) {
        int status;
        pid_t finished_pid = wait(&status); 

        if (finished_pid > 0) {
            active_children--; 
            printf("child process exited (pid: %d)\n",finished_pid);
        } 
    }

    printf("all child processes have exited parent process exiting...\n");

    return 0;
}