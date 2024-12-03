#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee{
    int id;
    char name[50];

    struct address{
        char street[50];
        char city[50];
    }addr;

    struct employee *next;
};

int main(){
    struct employee *head = NULL;
    struct employee *current;

    current = malloc(sizeof(struct employee));
    current -> id = 1;
    strcpy(current -> name, "name1");
    strcpy(current -> addr.street,"street1");
    strcpy(current -> addr.city,"city1");
    current -> next = NULL;

    head = current;

    current = malloc(sizeof(struct employee));
    current -> id = 2;
    strcpy(current -> name, "name2");
    strcpy(current -> addr.street,"street2");
    strcpy(current -> addr.city,"city2");
    current -> next = NULL;

    head -> next = current;

    current -> next = malloc(sizeof(struct employee));
    current = current -> next;
    current -> id = 3;
    strcpy(current -> name, "name3");
    strcpy(current -> addr.street,"street3");
    strcpy(current -> addr.city,"city3");
    current -> next = NULL;

    current = head;
    while(current != NULL){
        printf("id: %d\nname: %s\nstreet: %s\ncity: %s\n\n", current->id, current->name, current->addr.street, current->addr.city);
        current = current -> next;
    }

    return 0;
}