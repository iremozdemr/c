#include <stdio.h>
#include <stdlib.h>

struct person {
    int id;
    char firstname[20];
    char lastname[20];
};

int main(){

    FILE *file = fopen("file.bin","rb");

    if(file == NULL){
        printf("error");
        exit(1);
    }

    struct person p1;
    struct person p2;

    fread(&p1,sizeof(p1),1,file);
    fread(&p2,sizeof(p2),1,file);

    printf("p1: \n");
    printf("id: %i \n",p1.id);
    printf("firstname: %s \n",p1.firstname);
    printf("lastname: %s \n",p1.lastname);

    printf("p2: \n");
    printf("id: %i \n",p2.id);
    printf("firstname: %s \n",p2.firstname);
    printf("lastname: %s \n",p2.lastname);

    fclose(file);

    return 0;
}