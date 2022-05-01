#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue* next;
};

struct queue* front;
struct queue* rear;

void enqueue();
void dequeue();
void display();

void main() {
    int n;

    printf("\nEnter no. of nodes you want to create: ");
    scanf("%d", &n);

    if(n == 0) {
        printf("\nNo node created!\n");
        exit(0);
    }

    while(n--)
        enqueue();

    dequeue();
    display();
}

void enqueue() {
    struct queue* node;
    static struct queue* prev;

    node = (struct queue*)malloc(sizeof(struct queue));

    if(node == NULL) {
        printf("\nOut of memory!\n");
        exit(1);
    }

    rear = node;
    printf("\nEnter data: ");
    scanf("%d", &rear->data);

    if(front == NULL) {
        front = node;
        prev = front;
    }
    else {
        prev->next = node;
        prev = node;
    }
}

void dequeue() {
    struct queue* temp;

    if(rear == NULL) {
        printf("\nQueue is empty!\n");
        exit(0);
    }
    else if(front == rear) {
        front = rear = NULL;
    }
    else {
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    struct queue* temp;

    if(front == NULL) {
        printf("\nQueue is empty!\n");
        exit(0);
    }

    temp = front;

    while(temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}