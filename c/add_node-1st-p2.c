#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *createList(struct node*);
struct node* addNode(struct node*);

void main()
{
    struct node *start, *move;
    int c = 1;

    start = createList(start);
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

struct node *createList(struct node* start)
{
    struct node *p, *nd;
    int data, i, n;

    nd = (struct node*)malloc(sizeof(struct node));

    if(nd == NULL)
    {
        printf("\nOut of memory");
        return start;
    }

    start = nd;
    p = start;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("\nNo node created\n");
        exit(0);
    }

    printf("\nEnter data of 1 node: ");
    scanf("%d", &start->data);

    start->next = NULL;

    for(i = 2; i <= n; i++)
    {
        nd = (struct node*)malloc(sizeof(struct node));

        if(nd == NULL)
        {
            printf("\nOut of memory");
            return start;
        }

        printf("Enter data of %d node: ",i);
        scanf("%d", &data);

        nd->data = data;

        while(p->next != NULL)
        p = p->next;

        p->next = nd;
        nd->next = NULL;
    }

    return start;
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

    printf("\nEnter data of new node: ");
    scanf("%d", &new->data);

    new->next = start;

    start = new;

    return start;
}