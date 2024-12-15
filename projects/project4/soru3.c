//ÖNEMLİ: !!!!!!!!!!!!!!!!!!!!!!
//command line argument olarak 3 değer verilmelidir
//sırasıyla M N K

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int rowsA;
int colsA;

int rowsB;
int colsB;

int **A;
int **B;
int **AB;

void* matrixMultiplication(void* arg) {
    int col = *(int*)arg;
    free(arg);
    for (int i = 0; i < rowsA; i++) {
        AB[i][col] = 0;
        for (int k = 0; k < colsA; k++) {
            AB[i][col] += A[i][k] * B[k][col];
        }
    }
    return NULL;
}

int main(int argc, char* argv[]){
    if (argc != 4) {
        perror("you should enter 3 command line arguments: M N K");
        return 1;
    }

    rowsA = atoi(argv[1]);
    colsA = atoi(argv[2]);
    rowsB = atoi(argv[2]);
    colsB = atoi(argv[3]);

    if (rowsA <= 0 || colsA <= 0 || colsB <= 0) {
        perror("you entered false values for matrix dimensions");
        return 1;
    }

    int rowsAB = rowsA;
    int colsAB = colsB;

    A = (int**) malloc(rowsA * sizeof(int*)); 

    if(A == NULL){
        perror("memory allocation error for matrix A");
    }

    for(int i=0; i<rowsA; i++){
        A[i] = (int*) malloc(colsA * sizeof(int)); 
        if (A[i] == NULL) {
            perror("memory allocation error");
            return 1;
        }
    }

    B = (int**) malloc(rowsB * sizeof(int*)); 

    if(B == NULL){
        perror("memory allocation error for matrix B");
    }

    for(int i=0; i<rowsB; i++){
        B[i] = (int*) malloc(colsB * sizeof(int)); 
        if (B[i] == NULL) {
            perror("memory allocation error");
            return 1;
        }
    }

    AB = (int**) malloc(rowsAB * sizeof(int*)); 

    if(AB == NULL){
        perror("memory allocation error for matrix AB");
    }

    for(int i=0; i<rowsAB; i++){
        AB[i] = (int*) malloc(colsAB * sizeof(int)); 
        if (AB[i] == NULL) {
            perror("memory allocation error");
            return 1;
        }
    }

    for(int i=0; i<rowsA; i++){
        for(int j=0; j<colsA; j++){
            A[i][j] = rand()%10;
        }
    }

    for(int i=0; i<rowsB; i++){
        for(int j=0; j<colsB; j++){
            B[i][j] = rand()%10;
        }
    }

    pthread_t* threads = (pthread_t*)malloc(colsB * sizeof(pthread_t));

    for (int j = 0; j < colsB; j++) {
        int* col = malloc(sizeof(int));
        if (col == NULL) {
            perror("memory allocation error");
            free(threads);
            return 1;
        }
        *col = j;
        if (pthread_create(&threads[j], NULL, matrixMultiplication, col) != 0) {
            perror("pthread_create");
            free(threads);
            free(col);
            return 1;
        }
    }

    for (int j = 0; j < colsB; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("matrix A: \n");
    for(int i=0; i<rowsA; i++){
        for(int j=0; j<colsA; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("matrix B: \n");
    for(int i=0; i<rowsB; i++){
        for(int j=0; j<colsB; j++){
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }

    printf("matrix AB: \n");
    for(int i=0; i<rowsAB; i++){
        for(int j=0; j<colsAB; j++){
            printf("%d ",AB[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<rowsA; i++){
        free(A[i]);
    }

    for(int i=0; i<rowsB; i++){
       free(B[i]);
    }

    for(int i=0; i<rowsAB; i++){
       free(AB[i]);
    }

    free(A);
    free(B);
    free(AB);
    free(threads);

    return 0;
}