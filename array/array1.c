#include <stdio.h>

int main(){
    int array1[5] = {1,2,3,4,5};
    int array2[] = {1,2,3,4,5};

    int array3[5] = {1,2};
    //arrayin uzunlugundan daha az eleman eklenebilir

    int array4[2] = {1,2,3,4,5};
    //arrayin uzunlugundan daha fazla eleman eklenebilir
    //error verir ama yine de kod çalışır

    int array5[5] = {2,4,6,8,10};
    printf("%d \n",array5[7]);
    //no index out of bounds checking
    //error verir ama yine de kod çalışır

    int array6[2][3] = {10,20,30,40,50,60};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",array6[i][j]);
        }
    }
    printf("\n");

    int array7[2][3] = {{10,20,30},{40,50,60}};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",array7[i][j]);
        }
    }
    printf("\n");

    int array8[][3] = {10,20,30,40,50,60};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",array8[i][j]);
        }
    }
    printf("\n");

    int array9[][3][2] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                printf("%d ",array9[i][j][k]);
            }
        }
    }
    printf("\n");
    //[number of 2d arrays]
    //[number of rows in each 2d array]
    //[number of columns in each 2d array]
    
    return 0;
}
//2d ve 3d arraylarda en soldaki size hariç
//tüm size'lar yazılmalıdır

//array type void olamaz
//array type function olamaz

//int myArray1[];
//yanlış
//int myArray2[5];
//doğru