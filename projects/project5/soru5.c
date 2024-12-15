#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LEN 256

int main() {
    char path[MAX_LEN];

    while (1) {
        printf("enter a path (or type 'exit' to quit): ");

        fgets(path, MAX_LEN, stdin);

        size_t len = strlen(path);
        if (len > 0 && path[len - 1] == '\n') {
            path[len - 1] = '\0';
        }

        if (strcmp(path, "exit") == 0) {
            printf("exiting...\n");
            break;
        }

        pid_t pid = fork();
        
        if (pid == 0) {
            printf("executing: ls -l %s\n", path);

            char *args[] = {"/bin/ls", "-l", path, NULL};

            execv("/bin/ls", args);

            exit(1);
        } 
        else {
            int status;
            waitpid(pid, &status, 0); 

            if (WIFEXITED(status)) {
                printf("child process exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}