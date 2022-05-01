#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* pre;
};

struct node* createn(struct node*);

struct node* deleteln(struct node*);

void main() {
    struct node* start;

    start = createn(start);

    start = deleteln(start);

    while(start != NULL) {
        printf("\n%d", start->data);

        start = start->next;
    }

    printf("\n");
}

struct node* createn(struct node* start) {
    struct node *n1, *p;
    int n;

    printf("\nEnter no. of nodes to create: ");
    scanf("%d", &n);

    n1 = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data of 1 node: ");
    scanf("%d", &n1->data);

    start = n1;
    p = start;

    for(int i = 2; i <= n; i++) {
        n1 = (struct node*)malloc(sizeof(struct node));

        printf("Enter data of %d node: ", i);
        scanf("%d", &n1->data);

        p->next = n1;
        n1->pre = p;

        p = n1;
    }

    return start;
}

struct node* deleteln(struct node* start) {
    struct node* temp = start;

    while(temp->next != NULL)
        temp = temp->next;
    
    temp->pre->next = NULL;
    free(temp);

    return start;
}