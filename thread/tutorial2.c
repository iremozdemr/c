#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myThreadFunction(void* arg) {
    printf("thread is running...\n");
    sleep(2);
    pthread_exit((void*)42); 
    //thread'i 42 değeri ile sonlandır
}

int main() {
    pthread_t thread_id;
    void* retval;

    pthread_create(&thread_id, NULL, myThreadFunction, NULL);

    printf("main thread is waiting for the created thread...\n");
    pthread_join(thread_id, &retval);

    printf("thread returned value: %ld\n",(long)retval);

    return 0;
}