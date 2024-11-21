#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "w");  

    if (file == NULL) {  
        printf("dosya acilamadi\n");
        return 1;
    }

    char text[] = "dosya islemleri";

    for(int i=0; text[i] != '\0'; i++){
        fputc(text[i],file);
    }

    fclose(file); 

    return 0;
}