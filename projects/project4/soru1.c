#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LEN 256

void handle_sigint(int sig) {
    printf("\n");
    printf("SIGINT detected signal: %d ", sig);
    printf("terminating\n");
    fflush(stdout);
    kill(0, SIGTERM); 
}

void removeNewline(char *input) {
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0'; 
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    int fd[2];
    char input[MAX_LEN];

    if (pipe(fd) != 0) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[1]); 

        while (1) {
            ssize_t bytes = read(fd[0], input, MAX_LEN);
            if (bytes <= 0) {
                break; 
            }

            input[bytes] = '\0'; 
            reverseString(input);   
            printf("reversed string: %s\n", input);
            fflush(stdout); 
        }

        close(fd[0]); 
    } else if (pid > 0) {
        close(fd[0]);

        signal(SIGINT, handle_sigint);

        while (1) {
            printf("please enter a string of max length %d: ", MAX_LEN - 1);
            printf("\n");
            fflush(stdout);

            if (fgets(input, MAX_LEN, stdin) == NULL) {
                printf("\nend of input\n");
                fflush(stdout);
                break;
            }

            removeNewline(input);
            write(fd[1], input, strlen(input) + 1); 
        }

        close(fd[1]); 
        wait(NULL);   
    } 
    else {
        perror("fork");
        return 1;
    }

    return 0;
}