#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list* prev;
    struct list* next;
};

void create();
void display();
void reverse();
void swap();

static struct list* start;
static int length;

int main() {
    create();
    display();

    reverse();
    display();

    return 0;
}

void create() {
    struct list *node, *pre;
    int n;

    printf("\nEnter no. of nodes to create: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("\nNo nodes created!\n");
        return;
    }

    for(int i = 1; i <= n; i++) {
        node = (struct list*)malloc(sizeof(struct list));

        if(!node) {
            printf("\nOut of memory!\n");
            exit(1);
        }

        printf("\nEnter data: ");
        scanf("%d", &node->data);

        if(start == NULL) {
            start = pre = node;
            start->prev = NULL;
            start->next = NULL;
        }
        else {
            node->prev = pre;
            node->next = NULL;

            pre->next = node;
            pre = node;
        }

        length++;
    }
}

void display() {
    struct list* move;

    if(start == NULL) {
        printf("\nList doesn't exist!\n");
        return;
    }

    move = start;

    printf("\nList: ");
    while(move != NULL) {
        printf("%d ", move->data);
        move = move->next;
    }

    printf("\n");
}

void swap(struct list* a, struct list* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void reverse() {
    struct list *f, *s;

    if(start == NULL) {
        printf("\nList doesn't exist!\n");
        return;
    }

    f = s = start;

    while(s->next != NULL)
        s = s->next;
    
    for(int i = 1; i <= length/2; i++) {
        swap(f, s);

        f = f->next;
        s = s->prev;
    }
}