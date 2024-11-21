#include <stdio.h>

int main(){
    FILE *file = fopen("filename.txt", "r");  

    if (file == NULL) {  
        printf("dosya bulunamadi\n");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, 100, file)) {  // satır satır oku
        printf("%s", buffer);  // ekrana yazdır
    }

    fclose(file); 
    return 0;
}