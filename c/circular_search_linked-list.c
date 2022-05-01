#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void *search(struct node *);

void main()
{
    struct node *start, *n1, *n2, *n3;

    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));

    start=n1;

    printf("\nEnter data: ");
    scanf("%d",&start->data);
    start->next=n2;

    printf("Enter data: ");
    scanf("%d",&n2->data);
    n2->next=n3;

    printf("Enter data: ");
    scanf("%d",&n3->data);
    n3->next=start;

    search(start);
}

void *search(struct node* start)
{
    int n=1,data;
    struct node *temp=start;

    printf("\nEnter data to search: ");
    scanf("%d",&data);

    while(1)
    {
        if(temp->data==data)
        {

            printf("\nData founded on node %d\n",n);
            exit(0);
        }
        temp=temp->next;

        if(temp==start)
        {
            printf("\nData not founded\n");
            exit(0);
        }

        n++;
    }
    
}