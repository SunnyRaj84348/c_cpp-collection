#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

int queue[MAX];
int front = -1;
int rear = -1;

bool is_empty();
bool is_full();
void enqueue(int data);
void dequeue();
void peek();
void display();

int main() {
    enqueue(1);
    enqueue(2);
    dequeue();
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    return 0;
}

void enqueue(int data) {
    if(is_full()) {
        printf("\nQueue is full!\n");
        return;
    }

    if(is_empty())
        front = rear = 0;
    else if(rear == MAX-1)
        rear = 0;
    else
        rear++;
    
    queue[rear] = data;
}

void dequeue() {
    if(is_empty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    int data = queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;
    
    printf("\nElement removed: %d", data);
}

void peek() {
    if(is_empty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n%d", queue[front]);
}

void display() {
    if(is_empty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    int i = front;

    printf("\nQueue: ");
    if(front <= rear) {
        while(i <= rear)
            printf("%d ", queue[i++]);
    }
    else {
        while(i < MAX)
            printf("%d ", queue[i++]);
        
        i = 0;

        while(i <= rear)
            printf("%d ", queue[i++]);
    }
}

bool is_empty() {
    if(front == -1)
        return 1;
    
    return 0;
}

bool is_full() {
    if(front == rear+1 || (front == 0 && rear == MAX-1) )
        return 1;
    
    return 0;
}