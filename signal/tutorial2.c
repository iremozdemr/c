//alarm:
//her process'in bir alarm clock timer'ı vardır
//SIGALRM sinyalini göndermek için kullanılır

//eğer daha önce ayarlanmış bir alarm varsa 
//bu alarmın kalan süresini döner
//eğer daha önce ayarlanmış bir alarm yoksa 
//0 döner

//unsigned int alarm(unsigned int seconds)

//seconds: 
//alarm süresini belirtir
//seconds eğer 0 olarak verilirse daha önce ayarlanmış herhangi bir alarm devre dışı bırakılır

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("setting an alarm for 3 seconds...\n");
    alarm(3); 
    //3 saniye sonra SIGALRM sinyali gönder

    printf("waiting for the alarm...\n");
    pause(); 
    //sinyal gelene kadar bekle

    printf("this will not be printed unless SIGALRM is handled\n");
    return 0;
}