//int pthread_create(pthread_t *thread,pthread_attr_t *attr,void* (*start_routine)(void*),void *arg)
//thread oluşturur
//pthread_t *thread:
//oluşturulan thread'in thread id'sini tutar
//pthread_attr_t *attr:
//thread özelliklerini belirtir
//varsayılan özellikleri kullanmak için null yapılır
//void* (*start_routine)(void*):
//thread'in çalıştıracağı fonksiyon
//bu fonksiyonun return type'ı void* olmalıdır
//bu fonksiyon bir parametre almalıdır
//void *arg:
//thread'e geçilecek tek bir argüman
//epğer arguman yoksa null yapılır

//void pthread_exit(void *retval)
//bir thread'i sonlandırır
//retval:
//thread'in döneceği değer

//int pthread_join(pthread_t th, void **thread_return)
//belirtilen thread'in sonlanması beklenir
//th:
//beklenecek thread'in thread id'si
//thread_return:
//thread'in döneceği değer

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// İş parçacığı tarafından çalıştırılacak fonksiyon
void* myThreadFunction(void* arg) {
    printf("thread is running...\n");
    sleep(2);
    return NULL;
}

int main() {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, myThreadFunction, NULL);

    printf("main thread is waiting for the created thread...\n");
    pthread_join(thread_id, NULL);

    printf("thread has finished execution\n");

    return 0;
}