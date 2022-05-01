#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list* next;
} list;

list* front = NULL;
list* back = NULL;

void insert(int data) {
    list* node;
    node = (list*)malloc(sizeof(list));

    if(node == NULL) {
        printf("Memory can't be allocated!\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    if(front == NULL) {
        front = back = node;
    }
    else {
        back->next = node;
        back = node;
    }
}

void push_back(int data) {
    if(back == NULL) {
        printf("\nEmpty list!\n");
        return;
    }

    list* node;
    node = (list*)malloc(sizeof(list));

    if(node == NULL) {
        printf("Memory can't be allocated!\n");
        return;
    }

    node->data = data;
    node->next = NULL;

    back->next = node;
    back = node;
}

void pop_back() {
    if(back == NULL) {
        printf("\nEmpty list!\n");
        return;
    }

    if(front == back) {
        free(front);
        front = back = NULL;
        return;
    }

    list* ptr = front;
    while(ptr->next != back)
        ptr = ptr->next;
    
    ptr->next = NULL;
    free(back);
    back = ptr;
}

void push_front(int data) {
    if(front == NULL) {
        printf("\nEmpty list!\n");
        return;
    }

    list* node;
    node = (list*)malloc(sizeof(list));

    if(node == NULL) {
        printf("Memory can't be allocated!\n");
        return;
    }

    node->data = data;
    node->next = front;

    front = node;
}

void pop_front() {
    if(front == NULL) {
        printf("\nEmpty list!\n");
        return;
    }

    if(front == back) {
        free(front);
        front = back = NULL;
        return;
    }

    list* ptr = front->next;
    free(front);
    front = ptr;
}

void display() {
    if(front == NULL) {
        printf("Empty list!\n");
        return;
    }

    list* ptr = front;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main() {
    insert(45);
    insert(87);
    insert(54);
    push_back(556);
    push_back(600);

    pop_back();
    push_front(456);
    push_front(568);
    pop_front();

    display();

    return 0;
}