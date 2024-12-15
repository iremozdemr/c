#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("you entered invalid command line argument");
        return 1;
    }

    int fd[2]; 
    if (pipe(fd) == -1) { 
        perror("pipe");
        return 1;
    }

    pid_t pid1 = fork(); 

    if (pid1 == 0) {
        close(fd[0]); 
        if (dup2(fd[1], STDOUT_FILENO) == -1) { 
            perror("dup2");
            exit(1);
        }
        close(fd[1]); 

        char *ls_args[] = {"/bin/ls", "-1", argv[1], NULL};
        execv(ls_args[0], ls_args);

        perror("execv ls");
        exit(1);
    } 
    else if (pid1 > 0) {
        pid_t pid2 = fork();

        if (pid2 == 0) {
            close(fd[1]); 
            if (dup2(fd[0], STDIN_FILENO) == -1) { 
                perror("dup2");
                exit(1);
            }
            close(fd[0]); 

            char *wc_args[] = {"/usr/bin/wc", "-w", NULL};
            execv(wc_args[0], wc_args);

            perror("execv wc");
            exit(1);
        } else if (pid2 > 0) {
            close(fd[0]);
            close(fd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0); 
        } else {
            perror("fork");
            return 1;
        }
    } 
    else {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    return 0;
}