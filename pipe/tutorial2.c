//dup:
//mevcut bir file descriptor'ı kopyalamak için kullanılır
//kopyalanan file descriptor orijinal file descriptor ile aynı özelliklere sahiptir
//bu iki file descriptor aynı dosya üzerinde aynı konumu paylaşır
//bu iki file descriptor aynı dosya üzerinde aynı erişim izinlerini paylaşır 
//exec fonksiyonu çağrılsa bile yeni file descriptor açık kalır

//int dup(int oldfd)
//oldfd: kopyalanacak olan file descriptor

//başarı durumunda 
//yeni file descriptor'ın numarasını döner
//hata durumunda 
//-1 döner

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    //dosyayı yazma modu ile aç

    int newfd = dup(fd);
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