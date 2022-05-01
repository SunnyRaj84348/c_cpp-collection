#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *pre;
};

struct node *createlist(struct node*);

void main()
{
    struct node *start, *move;

    start=createlist(start);

    move=start;

    while(move!=NULL)
    {
        printf("\nData = %d",move->data);
        move=move->next;
    }

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

    start->next=NULL;
    start->pre=NULL;

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

        while(p->next!=NULL)
        p=p->next;
        
        p->next=nd;
        nd->pre=p;
        nd->next=NULL;
    }

    return start;
}

