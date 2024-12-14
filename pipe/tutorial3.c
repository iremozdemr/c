#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    //dosyayı yazma modu ile aç

    int newfd;
    dup2(fd,newfd);
    //file descriptor'ı kopyala

    write(fd, "merhaba, bu fd ile yazildi\n",28);
    //orijinal file descriptor'ı kullanarak yaz

    write(newfd, "merhaba, bu newfd ile yazildi\n",32);
    //kopyalanan file descriptor'ı kullanarak yaz

    close(fd);
    close(newfd);
    //file descriptor'ları kapat

    return 0;
}