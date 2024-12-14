#include <stdio.h>
#include <unistd.h>

int main() {
    printf("setting an alarm for 10 seconds...\n");
    alarm(10);
    //10 saniyelik alarm ayarla

    sleep(3);

    printf("setting an alarm for 5 seconds...\n");
    unsigned int remaining = alarm(5);
    //5 saniyelik alarm ayarla

    printf("%u\n",remaining);

    return 0;
}