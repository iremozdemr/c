//pid_t wait(int *status)
//parent process child process'in bitmesini bekler
//child process bitince:
//wait fonksiyonu biten child process'in pid'sini döner
//status parametresine bu process'in durumunu yazar

//eğer child process yoksa wait fonksiyonu -1 döner

//pid_t wait(pid_t pid,int *status,int options)
//parent process belirli bir child process'in bitmesini bekler
//child process bitince
//wait fonksiyonu biten child process'in pid'sini döner
//status parametresine bu process'in durumunu yazar

//eğer fork() 0 dönerse:
//pid = 0
//kod child process'dedir

//eğer fork() 0'dan büyük bir sayı dönerse:
//pid > 0
//kod parent process'dedir

//eğer fork() 0'dan küçük bir sayı dönerse:
//pid < 0
//hata

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    printf("pid: %d\n", getpid());

    if(pid == 0){
        //child process

        printf("child process running (pid: %d)\n", getpid());
        sleep(2);
        printf("child process exiting...\n");
        exit(42); 
    } 
    else if(pid > 0){
        //parent process

        int status;
        printf("parent process waiting for child...\n");
        pid_t child_pid = wait(&status);

        printf("child process (pid: %d) finished\n", child_pid);

        if(WIFEXITED(status)){
            printf("child exited with status: %d\n", WEXITSTATUS(status));
        }
    } 
    else{
        perror("fork failed");
    }

    return 0;
}