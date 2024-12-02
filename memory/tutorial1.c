//malloc:
//dinamik bellek tahsisi yapar
//runtime'da heap üzerinde belirli boyutta bellek ayırır
//tahsis edilen belleği sıfırlamaz
//void * malloc(size_t size);
//size_t size   -> ayırmak istenilen bellek miktarı (byte cinsinden)
//void *        -> başarılı olursa tahsis edilen bellek bloğunun başlangıç adresini döner

//calloc:
//tahsis edilen belleği sıfırlar
//void* calloc(size_t n, size_t size);
//size_t n      -> ayırmak istenilen element sayısı
//size_t size   -> ayırmak istenilen bellek miktarı (byte cinsinden)
//void *        -> başarılı olursa tahsis edilen bellek bloğunun başlangıç adresini döner

//realloc:
//tahsis edilen belleğin büyüklüğünü değiştirir
//ilk parametre NULL yapılırsa malloc gibi davranır
//ikinci parametre 0 yapılırsa free gibi davranır
//void* realloc(void *ptr, size_t size);
//void *ptr     -> daha önce ayrılmış belleği gösteren pointer
//size_t size   -> ayırmak istenilen yeni bellek miktarı (byte cinsinden)

//free:
//void free(void * pointer);

#include <stdio.h>
#include <stdlib.h>

int main() {

    int* p1 = (int*) malloc(sizeof(int));  

    if(p1 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    *p1 = 42;  
    
    printf("değer: %d\n", *p1);

    free(p1);  


    int* p2 = (int*) calloc(1,sizeof(int));  

    if(p2 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    *p2 = 42;  
    
    printf("değer: %d\n", *p2);

    free(p2);  

    return 0;
}