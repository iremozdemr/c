#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    struct person{
        char name[50];
        int age;
    };

    int n = 3;

    struct person *people = (struct person*) calloc(n,sizeof(struct person));

    if(people == NULL){ 
        printf("bellek tahsisi basarisiz \n");
        return 1;
    }

    for(int i=0; i<n; i++){
        strcpy(people[i].name,"alice");
        people[i].age = 3;
    }

    printf("name: %s\n",people[0].name);
    printf("age: %d\n",people[0].age);

    printf("name: %s\n",people[1].name);
    printf("age: %d\n",people[1].age);

    printf("name: %s\n",people[2].name);
    printf("age: %d\n",people[2].age);

    free(people);

    return 0;
}