#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char fname[20];
    char lname[20];
};

int main(){

    FILE *file = fopen("file.bin","wb");

    if(file == NULL){
        printf("error");
        exit(1);
    }

    struct person p1 = {1,"a","abc"};
    struct person p2 = {2,"b","xyz"};

    fwrite(&p1,sizeof(struct person),1,file);
    fwrite(&p2,sizeof(struct person),1,file);

    fclose(file);

    return 0;
}