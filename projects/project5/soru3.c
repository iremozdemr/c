#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void signal_handle(int sig) {
    printf("caught signal %d\n", sig);

    if (sig == SIGINT) {
        printf("caught sigint (%d)\n", sig);
        kill(0, SIGTERM); 
    }
}

int main() {
    int fd[2]; 

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid > 0) {
        signal(SIGINT, signal_handle); 
        close(fd[0]);                

        char input[256];

        while (1) {
            printf("enter a string: ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                size_t len = strlen(input);
                if (len > 0 && input[len - 1] == '\n') {
                    input[len - 1] = '\0';
                }

                write(fd[1], input, strlen(input) + 1);
            }
        }
    } 
    else if (pid == 0) {
        close(fd[1]);

        char buffer[256];

        while (1) {
            ssize_t bytes_read = read(fd[0], buffer, sizeof(buffer));
            if (bytes_read > 0) {
                printf("string: %s\n", buffer);
            } 
            else if (bytes_read == 0) {
                break;
            } 
        }

        close(fd[0]); 
    }

    return 0;
}