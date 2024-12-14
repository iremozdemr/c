#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* myThreadFunction(void* arg) {
    int id = *((int*)arg);
    printf("thread %d is running...\n", id);
    sleep(2);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, myThreadFunction, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("all threads have finished\n");

    return 0;
}