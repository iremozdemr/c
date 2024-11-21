#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "r");  

    if (file == NULL) {  
        printf("dosya acilamadi\n");
        return 1;
    }

    char mychar;

    while((mychar = fgetc(file)) != EOF){
        printf("%c", mychar);
    }

    fclose(file); 

    return 0;
}