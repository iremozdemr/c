//pipe:
//process'ler arasında bilgi iletir
//bir process veri yazar diğer process bu veriyi okur
//dosya benzeri bir yapı kullanılır
//fifo
//read end'e sahiptir
//write end'e sahiptir

//bir process dolu bir pipe'a veri yazmaya çalışırsa
//reader bir miktar veri tüketene kadar beklenir
//bir process boş bir pipe'dan veri okumaya çalışırsa
//writer bir miktar veri sağlayana kadar beklenir

//iki tür pipe vardır
//unnamed pipes
//named pipes

//unnamed pipes:
//birbiriyle alakalı process'lerde kullanılır
//bu process'ler bitene kadar pipe kalır
//parent - child
//child - child

//named pipes:
//birbiriyle alakalı olmayan process'lerde kullanılır
//normal dosyalar gibi erişim izinlerine sahiptir (read write execute)

//pipe():
//pipe oluşturur
//veriler write() ile yazılır
//veriler read() ile okunur

//int pipe(int fd[2])
//fd 2 elemanlı bir array olmalıdır
//fd[0] -> read end
//fd[1] -> write end

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[128];
    const char *message = "hello from parent process!";

    pipe(fd);
    //pipe oluştur

    pid_t pid = fork();

    if (pid == 0) {
        //child process: reader
        printf("pid: %d\n",pid);

        close(fd[1]); 
        //yazmayı kapat
        read(fd[0], buffer, sizeof(buffer));
        printf("child process received: %s\n", buffer);
        close(fd[0]);
        //okumayı kapat
    } 
    else {
        //parent process: writer
        printf("pid: %d\n",pid);

        close(fd[0]); 
        //okumayı kapat
        write(fd[1], message, strlen(message) + 1);
        printf("parent process sent: %s\n", message);
        close(fd[1]);
        //yazmayı kapat
    }

    return 0;
}