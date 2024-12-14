#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();

    if (pid1 == 0) {
        //child process 1:
        printf("child 1 running (pid: %d)\n", getpid());
        sleep(3);
        printf("child 1 exiting...\n");
        exit(10);
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {
        //child process 2:
        printf("child 2 running (pid: %d)\n", getpid());
        sleep(1);
        printf("child 2 exiting...\n");
        exit(20);
    }

    //parent process
    int status;

    printf("parent waiting for child 2 (pid: %d)...\n", pid2);
    pid_t finished_pid2 = waitpid(pid2, &status, 0);

    printf("parent waiting for child 1 (pid: %d)...\n", pid1);
    pid_t finished_pid1 = waitpid(pid1, &status, 0);

    return 0;
}