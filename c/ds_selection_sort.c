#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createlist(struct node*);
void sort(struct node*);
void disp(struct node*);

void main()
{
    struct node *start;

    start = createlist(start);
    sort(start);
    disp(start);
}

struct node* createlist(struct node* start)
{
    struct node *p, *nd;
    int n;

    nd = (struct node*)malloc(sizeof(struct node));

    if(nd == NULL)
    {
        printf("\nOut of memory\n");
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
        scanf("%d", &nd->data);

        p->next = nd;
        nd->next = NULL;
        p = nd;
    }

    return start;
}

void sort(struct node* start)
{
    struct node *p, *q;
    int tmp;

    for(p = start; p->next != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->data > q->data)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
}

void disp(struct node* start)
{
    struct node* move = start;

    while(move != NULL)
    {
        printf("\nData = %d", move->data);
        move = move->next;
    }

    printf("\n");
}