//SEEK_SET:
//dosyanın başlangıcı

//SEEK_END:
//dosyanın sonu

//SEEK_CUR:

#include <stdio.h>

int main(){
    FILE* file = fopen("filename.txt", "r");

    fseek(file, 0, SEEK_END);
    //moving pointer to end

    printf("%ld \n", ftell(file));
    //printing position of pointer

    fseek(file, 0, SEEK_SET);
    //moving pointer to end

    printf("%ld \n", ftell(file));
    //printing position of pointer

    fseek(file, 0, SEEK_CUR);
    //moving pointer to end

    printf("%ld \n", ftell(file));
    //printing position of pointer

    fclose(file);

    return 0;
}