#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* addNode(struct node*);

void main()
{
    struct node *start, *n1, *n2, *move;
    int c = 1;

    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));

    if(n1 == NULL || n2 == NULL)
    {
        printf("\nOut of memory\n");
        exit(1);
    }

    start = n1;

    printf("\nEnter data of 1st node: ");
    scanf("%d", &n1->data);
    n1->next = n2;

    printf("Enter data of 2nd node: ");
    scanf("%d", &n2->data);

    start = addNode(start);

    move = start;

    while(move != NULL)
    {
        printf("\nData of %d node = %d", c, move->data);
        move = move->next;

        c++;
    }

    printf("\n");
}

struct node* addNode(struct node* start)
{
    struct node* new;

    new = (struct node*)malloc(sizeof(struct node));

    if(new == NULL)
    {
        printf("\nOut of memory");
        return start;
    }

    printf("Enter data of new node: ");
    scanf("%d", &new->data);

    new->next = start;

    start = new;

    return start;
}