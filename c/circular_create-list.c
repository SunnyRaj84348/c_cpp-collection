#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *createlist(struct node*);

void main()
{
    struct node *start, *move;

    start=createlist(start);

    move=start;

    do
    {
        printf("\nData = %d",move->data);
        move=move->next;
    } while (move!=start);

    printf("\n");
}

struct node *createlist(struct node* start)
{
    struct node *p, *nd;
    int data,i,n;

    nd=(struct node*)malloc(sizeof(struct node));

    if(nd==NULL)
    {
        printf("\nOut of memory");
        return start;
    }

    start=nd;
    p=start;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d",&n);

    if(n==0)
    {
        printf("\nNo node created\n");
        exit(0);
    }

    printf("\nEnter data of 1 node: ");
    scanf("%d",&start->data);

    start->next=start;

    for(i=2; i<=n; i++)
    {
        nd=(struct node*)malloc(sizeof(struct node));

        if(nd==NULL)
        {
            printf("\nOut of memory");
            return start;
        }

        printf("Enter data of %d node: ",i);
        scanf("%d",&data);

        nd->data=data;

        p->next=nd;
        nd->next=start;
        p = nd;
    }

    return start;
}