#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

int isEmpty(node *head);
void printList(node *head);
node* search(node *head,int value);
int insert(node **headPointer,int value);
int delete(node **headPointer,int value);

int main(){
    node *head = NULL;

    if(isEmpty(head)){
        printf("list is empty \n");
    }
    else{
        printf("list is not empty \n");
    }

    insert(&head, 2); 
    insert(&head, 5); 
    insert(&head, 1);
    insert(&head, 6); 
    insert(&head, 3); 
    insert(&head, 4);

    if(isEmpty(head)){
        printf("list is empty \n");
    }
    else{
        printf("list is not empty \n");
    }
    
    printList(head);

    printList(search(head, 3));
    printList(search(head, 8));

    delete(&head, 0); 
    delete(&head, 7);
    delete(&head, 3); 
    delete(&head, 6); 
    delete(&head, 1);
    delete(&head, 4); 
    delete(&head, 5); 
    delete(&head, 2);
    
    if(isEmpty(head)){
        printf("list is empty \n");
    }
    else{
        printf("list is not empty \n");
    }

    return 0;
}

int isEmpty(node *head){
    return head == NULL;
}

void printList(node *head){
    while(head != NULL){
        printf("%d ",head -> data);
        head = head -> next;
    }
    printf("\n");
}

node* search(node *head,int value){
    while(head != NULL){
        if(head -> data == value){
            break;
        }
        else{
            head = head -> next;
        }
    }

    return head;
}

int insert(node **headPointer,int value){
    node *newnode = malloc(sizeof(node));

    if(newnode == NULL){
        printf("no memory available \n");
        return 0;
    }

    newnode -> data = value;
    node *prev = NULL;
    node *current = *headPointer;

    while(current != NULL && current -> data < value){
        prev = current;
        current = current -> next;
    }

    newnode -> next = current;

    if(prev == NULL){
        *headPointer = newnode;
    }
    else{
        prev -> next = newnode;
    }

    return 1;
}

int delete(node **headPointer,int value){
    node *prev = NULL;
    node *current = *headPointer;

    while (current != NULL && current -> data != value){
        prev = current;
        current = current -> next;
    }

    if(current == NULL){
        return 0;
    }

    if(current == *headPointer){
        *headPointer = (*headPointer) -> next;
    }
    else{
        prev -> next = current -> next;
    }

    free(current);

    return 1;
}