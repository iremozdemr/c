//getpid():
//current pid'yi döner

//getppid():
//parent pid'yi döner

//getpgid():
//belirtilen bir process'in grup pid'sini döner

//setpgid():
//belirtilen bir process'in grup pid'sini değiştirir

//pid_t:
//pid'leri saklamak için kullanılan bir veri türüdür
//genellikle int tipindedir
//<sys/types.h> 'de tanımlıdır

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();     
    //current process'in pid'si
    pid_t ppid = getppid();
    //parent process'in pid'si
    pid_t pgid = getpgid(0);

    printf("current process pid: %d\n", pid);
    printf("parent process pid: %d\n", ppid);
    printf("parent process pid: %d\n", pgid);

    return 0;
}