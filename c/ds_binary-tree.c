#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
    struct tree* left;
    int data;
    struct tree* right;
} tree;

#define MAX 100

tree* queue[MAX];
int front = -1;
int rear = -1;

bool qempty() {
    if(front == -1) return 1;
    return 0;
}

bool qfull() {
    if( front == rear+1 || (front == 0 && rear == MAX-1) )
        return 1;
    
    return 0;
}

void enqueue(tree* data) {
    if(qfull()) {
        printf("\nQueue is full!\n");
        return;
    }

    if(qempty())
        front = rear = 0;
    else if(front == rear && rear == MAX-1)
        rear = 0;
    else
        rear++;
    
    queue[rear] = data;
}

void dequeue() {
    if(qempty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    int data = queue[front]->data;

    if(front == rear)
        front = rear = -1;
    else
        front++;
    
    printf("%d ", data);
}

tree* insert(tree* root, int data) {
    if(root == NULL) {
        tree* node = (tree*)malloc(sizeof(tree));

        node->left = node->right = NULL;
        node->data = data;

        return node;
    }
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

tree* min_data(tree* root) {
    while(root->left != NULL)
        root = root->left;
    
    return root;
}

tree* delete(tree* root, int key) {
    if(root == NULL) return root;
    
    if(key < root->data) {
        root->left = delete(root->left, key);
    }   
    else if(key > root->data) {
        root->right = delete(root->right, key);
    }
    else {
        if(root->left == NULL) {
            tree* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        }
        else {
            tree* temp = min_data(root->right);
            root->data = temp->data;
            
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

void inorder(tree* root) {
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void b_search(tree* root, int data) {
    if(root == NULL) {
        printf("\nElement not founded\n");
        return;
    }

    if(root->data == data) {
        printf("\nElement founded\n");
        return;
    }
    else if(data < root->data)
        b_search(root->left, data);
    else
        b_search(root->right, data);
}

bool search(tree* root, int data) {
    bool a;
    if(root == NULL)
        return 0;

    if(root->data == data)
        return 1;

    a = search(root->left, data);
    a = search(root->right, data);

    return a;
}

void invert(tree* root) {
    if(root == NULL) return;

    tree* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invert(root->left);
    invert(root->right);
}

void order(tree* root) {
    enqueue(root);

    while(!qempty()) {
        if(queue[front]->left != NULL)
            enqueue(queue[front]->left);
        
        if(queue[front]->right != NULL)
            enqueue(queue[front]->right);
        
        dequeue();
    }
}

int main() {
    tree* root = NULL;

    root = insert(root, 50);
    insert(root, 15);
    insert(root, 60);
    insert(root, 12);
    insert(root, 17);
    insert(root, 55);
    insert(root, 70);
    insert(root, 71);

    order(root);
    printf("\n");

    invert(root);
    order(root);

    printf("\n");

    bool f = search(root, 150);
    if(f)
        printf("\nElement Founded\n");
    else
        printf("\nElement not founded!\n");
    
    printf("\n");

    return 0;
}