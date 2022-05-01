#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node();
struct node* delete_node(struct node*, int);
void display(struct node*);

void main() {
    struct node* start;

    start = create_node();

    start = delete_node(start, 5);

    display(start);
}

struct node* create_node() {
    struct node *start, *n1, *p;
    int n;

    printf("\nEnter total no. of nodes to create: ");
    scanf("%d", &n);

    if(n == 0) {
        printf("\nNo nodes created!\n");
        exit(1);
    }

    n1 = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data of 1 node: ");
    scanf("%d", &n1->data);

    start = n1;
    p = start;

    for(int i = 2; i <= n; i++) {
        n1 = (struct node*)malloc(sizeof(struct node));

        printf("\nEnter data of %d node: ", i);
        scanf("%d", &n1->data);

        p->next = n1;
        p = n1;
    }

    return start;
}

struct node* delete_node(struct node* start, int val) {
    struct node *temp = start, *pre;

    do {
        if(temp->data == val)
            break;
        
        pre = temp;
        temp = temp->next;
    } while(temp != NULL);

    if(temp == NULL) {
        printf("\nGiven data not founded in list!\n");
        return start;
    }
    else if(temp == start) {
        start = temp->next;
        free(temp);
    }
    else {
        pre->next = temp->next;
        free(temp);
    }

    printf("\nNode has been deleted\n");

    return start;
}

void display(struct node* start) {
    while(start != NULL) {
        printf("\n%d", start->data);
        start = start->next;
    }

    printf("\n");
}