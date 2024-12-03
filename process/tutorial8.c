#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        //parent process
        printf("parent process: \n");
        printf("pid of current process (parent): %d\n", getpid());
        printf("pid of child process: %d\n", pid);
    } 
    else if (pid == 0) {
        //child process
        printf("child process: \n");
        printf("pid of current process (child): %d\n", getpid());
        printf("pid of parent process: %d\n", getppid());
    } 
    else {
        printf("fork failed\n");
    }

    return 0;
}