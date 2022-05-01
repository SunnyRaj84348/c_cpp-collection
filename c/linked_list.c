#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list* next;
} list;

void insert(list** head, int data) {
    list* ptr = NULL;
    static list* pre_ptr = NULL;

    ptr = (list*)malloc(sizeof(list));

    if(ptr == NULL) {
        printf("Failed to allocate memory!\n");
        return;
    }

    if(*head == NULL) {
        *head = ptr;
    }
    else {
        pre_ptr->next = ptr;
    }

    ptr->data = data;
    ptr->next = NULL;
    pre_ptr = ptr;
}

void remove_first(list** head) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    list* temp = (*head);
    *head = (*head)->next;
    free(temp);
}

void remove_last(list* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    list* temp = NULL;

    while(head->next->next != NULL) {
        head = head->next;
    }

    temp = head->next;
    head->next = NULL;
    free(temp);
}

void delete(list** head) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    list *ptr, *temp;
    ptr = temp = *head;

    while(ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }

    *head = NULL;
}



void display(list* ptr) {
    if(ptr == NULL) {
        printf("List is empty!\n");
        return;
    }

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    list* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    remove_first(&head);
    remove_last(head);

    delete(&head);

    display(head);

    return 0;
}