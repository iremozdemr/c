#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "r");  

    if (file == NULL) {  
        printf("dosya acilamadi\n");
        return 1;
    }

    char mychar1;
    while((mychar1 = fgetc(file)) != EOF){
        printf("%c", mychar1);
    }

    char mychar2;
    while(1){
        mychar2 = fgetc(file);

        if(feof(file)){
            break;
        }

        printf("%c", mychar2);
    }

    fclose(file); 

    return 0;
}