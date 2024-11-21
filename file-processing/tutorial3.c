#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "a");  

    if (file == NULL) {  
        printf("dosya acilamadi\n");
        return 1;
    }

    fprintf(file,"hello world! \n");
    fprintf(file,"hiiii! \n");
    fprintf(file,"hello! \n");

    fclose(file); 

    return 0;
}