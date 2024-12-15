#include <stdio.h>

int main(){
    FILE* file1 = fopen("filename.txt","r");
    FILE* file2 = fopen("filename.bin","rb");

    if(file1 == NULL){
        printf("dosya acilamadi \n");
        return 1;
    }
    if(file2 == NULL){
        printf("dosya acilamadi \n");
        return 1;
    }

    char string1[300];
    while(fscanf(file1,"%s",string1) != EOF){
        printf("%s",string1);
    }
    //dosyadan okuma

    char string2[300];
    while(fgets(string2,300,file1) != NULL){
        printf("%s",string2);
    }
    //dosyadan okuma

    char mychar;
    while((mychar = fgetc(file1)) != EOF){
        printf("%c",mychar);
    }
    //dosyadan okuma

    int array[300];
    fread(array,sizeof(int),5,file2);
    for(int i=0; i<5; i++){
        printf("%d ",array[i]);
    }
    //dosyadan okuma

    fclose(file1);
    fclose(file2);

    return 0;
}