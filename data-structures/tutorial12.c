#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
}

typedef struct node node;

node* createNode(int value){
    node* newnode = (node*) malloc(sizeof(node));

    if(newnode == NULL){
        return NULL;
    }

    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}

void insert(node* root,int value){
    if(root == NULL){
        createNode(value);
    }
    else if(value <= root -> data){
        root -> left = insert(root -> left,value);
    }
    else{
        root -> right = insert(root -> right,value);
    }
}

void delete(node* root,int value){
    if(root == NULL){
    }
    else if(value <= root -> data){
        root -> left = delete(root -> left,value);
    }
    else{
        root -> right = delete(root -> right,value);
    }
}

node* delete(node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = delete(root->left, value);
    } 
    else if (value > root->data) {
        root->right = delete(root->right, value);
    } 
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

node* search(node* root, int value){
    if(root == NULL){
        return root;
    }
    else if(value == root -> data){
        return root;
    }
    else if(value < root -> data){
        root = root -> left;
        search(root,value);
    }
    else{
        root = root -> right;
        search(root,value);
    }
}

//left root right
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

//root left right
void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

//left right root
void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}