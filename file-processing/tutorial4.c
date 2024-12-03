#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "r");  

    if (file == NULL) {  
        printf("dosya acilamadi\n");
        return 1;
    }

    char mychar;

    //yöntem 1:
    while((mychar = fgetc(file)) != EOF){
        printf("%c", mychar);
    }

    //yöntem 2:
    while(1){
        mychar = fgetc(file);

        if(feof(file)){
            break;
        }

        printf("%c", mychar);
    }

    fclose(file); 

    return 0;
}