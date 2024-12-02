#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1 = 5;
    int* array1 = (int*) malloc(n1 * sizeof(int));  

    if(array1 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    for(int i=0; i<n1; i++){
        array1[i] = 1;
    }
    
    for(int i = 0; i < n1; i++){
        printf("%d \n", array1[i]);
    }

    free(array1);  


    int n2 = 5;
    int* array2 = (int*) calloc(n2,sizeof(int));  

    if(array2 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    for(int i=0; i<n2; i++){
        array2[i] = 1;
    }
    
    for(int i = 0; i < n2; i++){
        printf("%d \n", array2[i]);
    }

    free(array2);  

    return 0;
}