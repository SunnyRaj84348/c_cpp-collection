// Delete node from given data

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *pre,*next;
    int data;
};

struct node *del(struct node *start);

void main()
{
    struct node *start, *n1, *n2, *n3, *n4, *move;

    start=(struct node*)malloc(sizeof(struct node));
    n1=(struct node*)malloc(sizeof(struct node));
    n2=(struct node*)malloc(sizeof(struct node));
    n3=(struct node*)malloc(sizeof(struct node));
    n4=(struct node*)malloc(sizeof(struct node));
    move=(struct node*)malloc(sizeof(struct node));

    if(start==NULL)
    {
        printf("Out of memory\n");
        exit(1);
    }

    start=n1;

    printf("\nEnter data: ");
    scanf("%d",&n1->data);
    n1->next=n2;

    printf("Enter data: ");
    scanf("%d",&n2->data);
    n2->pre=n1;
    n2->next=n3;

    printf("Enter data: ");
    scanf("%d",&n3->data);
    n3->pre=n2;
    n3->next=n4;

    printf("Enter data: ");
    scanf("%d",&n4->data);
    n4->pre=n3;
    
    start=del(start);

    move=start;

    while(move!=NULL)
    {
        printf("\nData = %d",move->data);
        move=move->next;
    }
    
    printf("\n");
}

struct node *del(struct node *start)
{
    int d;
    struct node* temp;

    temp=(struct node*)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("Out of memory\n");
        return start;
    }

    label:
    printf("\nEnter data of the node to be removed: ");
    scanf("%d",&d);

    temp=start;

    if(temp->data==d)
    {
        start=temp->next;
        temp->next->pre=NULL;
        free(temp);

        return start;
    }

    while(temp!=NULL)
    {
        if(temp->data==d)
        break;
        else
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("\nIncorrect data\nDo you want to continue? ");
        printf("(Type 1 to continue or any other key to exit): ");
        scanf("%d",&d);

        if(d==1)
        goto label;
        else
        exit(0);
    }

    if(temp->next==NULL)
    {
        temp->pre->next=NULL;
        free(temp);

        return start;
    }

    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;

    free(temp);

    return start;
}