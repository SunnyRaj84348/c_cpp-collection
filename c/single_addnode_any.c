#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next; 
};

struct node* createlist(struct node*);
struct node* addNode(struct node*);
void display(struct  node*);

void main()
{
    struct node *start;

    start = createlist(start);
    start = addNode(start);
    display(start);
}

struct node* createlist(struct node* start)
{
    struct node *p, *nd;
    int data, n;

    nd=(struct node*)malloc(sizeof(struct node));

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

    for(int i = 2; i <= n; i++)
    {
        nd=(struct node*)malloc(sizeof(struct node));

        if(nd == NULL)
        {
            printf("\nOut of memory");
            return start;
        }

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        nd->data = data;

        p->next = nd;
        nd->next = NULL;
        p = nd;
    }

    return start;
}

struct node* addNode(struct node* start)
{
    int data;
    struct node *nd, *move = start;

    nd = (struct node*)malloc(sizeof(struct node));

    if(nd == NULL)
    {
        printf("\nOut of memory");
        return start;
    }

    printf("\nEnter data of existing node: ");
    scanf("%d", &data);

    while(move->data != data)
    {
        move = move->next;

        if(move == NULL)
        {
            printf("\nData not founded");
            exit(1);
        }
    }

    printf("\nEnter data for new node: ");
    scanf("%d", &nd->data);

    nd->next = move->next;
    move->next = nd;

    return start;
}

void display(struct node* start)
{
    struct node* move = start;

    while(move != NULL)
    {
        printf("\nData = %d", move->data);
        move = move->next;
    }

    printf("\n");
}

