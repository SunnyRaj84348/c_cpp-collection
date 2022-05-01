#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int heap[MAX];
int top = -1;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool is_empty() {
    if(top == -1) return 1;
    return 0;
}

bool is_full() {
    if(top == MAX-1) return 1;
    return 0;
}

void insert(int data) {
    if(is_full()) {
        printf("\nOverflow\n");
        return;
    }

    heap[++top] = data;

    if(top == 0)
        return;

    int i = top;
    while(heap[i] > heap[(i-1)/2]) {
        swap(heap+i, heap+(i-1)/2);
        i = (i-1)/2;
    }
}

void heapify(int i) {
    int largest = i;
    int l = (2*i)+1;
    int r = (2*i)+2;

    if(l <= top && heap[largest] < heap[l])
        largest = l;
    
    if(r <= top && heap[largest] < heap[r])
        largest = r;
    
    if(largest != i) {
        swap(heap+i, heap+largest);
        heapify(largest);
    }
}

void delete() {
    if(is_empty()) {
        printf("\nHeap is empty!\n");
        return;
    }

    swap(heap+0, heap+top);
    top--;

    heapify(0);
}

void display() {
    for(int i = 0; i <= top; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    insert(8);
    insert(4);
    insert(7);
    insert(5);
    insert(16);

    delete();

    display();

    return 0;
}