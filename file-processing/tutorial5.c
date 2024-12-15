#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "r");  

    if (file == NULL) {  
        printf("dosya bulunamadi\n");
        return 1;
    }
    
    char buffer1[100];
    while (fgets(buffer1, 100, file)) {  
        printf("%s", buffer1);  
    }

    char buffer2[100];
    while (fgets(buffer2, 100, file) != NULL) {  
        printf("%s", buffer2);  
    }

    fclose(file); 

    return 0;
}