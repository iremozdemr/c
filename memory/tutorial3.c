#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    struct person{
        char name[50];
        int age;
    };

    struct person *p1 = (struct person*) malloc(sizeof(struct person));
    struct person *p2 = (struct person*) malloc(sizeof(struct person));

    if(p1 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    if(p2 == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    //p1 -> name = "alice";
    strcpy(p1 -> name,"alice");
    p1 -> age = 2;

    //p2 -> name = "alice";
    strcpy(p2 -> name,"alice");
    p2 -> age = 13;

    printf("name: %s\n",p1 -> name);
    printf("age: %d\n",p1 -> age);

    printf("name: %s\n",p2 -> name);
    printf("age: %d\n",p2 -> age);

    free(p1);
    free(p2);

    return 0;
}