#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int data;
    int priority;
} priority_queue;

#define MAX 100

priority_queue queue[MAX];
int top = -1;

bool is_empty() {
    if(top == -1) return 1;
    return 0;
}

bool is_full() {
    if(top == MAX-1) return 1;
    return 0;
}

int get_high_pri() {
    int ind = 0;

    for(int i = 1; i <= top; i++) {
        if(queue[ind].priority == queue[i].priority
                    && queue[i].data > queue[ind].data) {
            ind = i;
        }
        else if(queue[i].priority > queue[ind].priority) {
            ind = i;
        }
    }

    return ind;
}

void push(int data, int pri) {
    if(is_full()) {
        printf("\nQueue is full!\n");
        return;
    }

    queue[++top].data = data;
    queue[top].priority = pri;
}

void pop() {
    if(is_empty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    int ind = get_high_pri();

    for(int i = ind; i < top; i++) {
        queue[i].data = queue[i+1].data;
        queue[i].priority = queue[i+1].priority;
    }
    
    top--;
}

void display() {
    if(is_empty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    for(int i = 0; i <= top; i++)
        printf("%d ", queue[i].data);
    
    printf("\n");
}

int comp(const void* a, const void* b) {
    return ( ((priority_queue*)a)->priority -
                ((priority_queue*)b)->priority );
}

void arrange() {
    qsort(queue, top+1, sizeof(priority_queue), comp);
}

int main() {
    push(10, 2);
    push(20, 3);
    push(11, 1000);
    push(2, 0);
    push(23, 5);

    pop();
    arrange();

    display();

    return 0;
}