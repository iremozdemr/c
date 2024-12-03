#include <stdio.h>

int main(){
    FILE* file = fopen("file.txt", "w+");

    fprintf(file, "hello world\n");

    rewind(file);

    char mychar;

    while((mychar = fgetc(file)) != EOF){
        printf("%c", mychar);
    }

    return 0;
}