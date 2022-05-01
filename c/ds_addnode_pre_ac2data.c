#include <stdio.h>
#include <stdlib.h>
struct list
{
    int roll;
    struct list *pre;
    struct list *next;    
};
typedef struct list list;
list *add(list *start, int data);
list *add_f(list *start, int n_data);
list *add_l(list *start, int n_data);

void main()
{
    list *start, *n1, *n2, *n3, *n4, *move;
    int data;
    start=(list *)malloc(sizeof(list));
    n1=(list *)malloc(sizeof(list));
    n2=(list *)malloc(sizeof(list));
    n3=(list *)malloc(sizeof(list));
    n4=(list *)malloc(sizeof(list));
    move=(list *)malloc(sizeof(list));

    if(start==NULL || n1==NULL || n2==NULL || n3==NULL || n4==NULL || move==NULL)
    {
        printf("Insufficient memory\n");
        exit(1);
    }

    start=n1;
    printf("Enter roll ");
    scanf("%d",&n1->roll);
    n1->next=n2;
    printf("Enter roll ");
    scanf("%d",&n2->roll);
    n2->pre=n1;
    n2->next=n3;
    printf("Enter roll ");
    scanf("%d",&n3->roll);
    n3->pre=n2;
    n3->next=n4;
    printf("Enter roll ");
    scanf("%d",&n4->roll);
    n4->pre=n3;

    printf("Enter data of existing node ");
    scanf("%d",&data);

    start=add(start,data);
    move=start;

    while(move!=NULL)
    {
        printf("\nRoll= %d",move->roll);
        move=move->next;
    }
    printf("\n");

}

list *add(list *start, int data)
{
    int n_data;

    printf("Enter data of new node ");
    scanf("%d",&n_data);

    if(data==start->roll)
    {
        start=add_f(start,n_data);
        return start;
    }

    list *temp;
    temp=(list *)malloc(sizeof(list));

    if(temp==NULL)
    {
        printf("Insufficient memory\n");
        return start;
    }

    temp=start;

    while(temp->roll!=data)
    temp=temp->next;

    if(temp->next==NULL)
    {
        start=add_l(start,n_data);
        return start;
    }

    list *n_node;
    n_node=(list *)malloc(sizeof(list));

    if(n_node==NULL)
    {
        printf("Insufficient memory\n");
        exit(1);
    }

    n_node->roll=n_data;
    n_node->pre=temp->pre;
    n_node->next=temp;
    temp->pre->next=n_node;
    temp->pre=n_node;

    return start;
}

list *add_f(list *start, int n_data)
{
    list *n_node;
    n_node=(list *)malloc(sizeof(list));

    if(n_node==NULL)
    {
        printf("Insufficient memory\n");
        return start;
    }

    n_node->roll=n_data;
    n_node->next=start;
    start->pre=n_node;
    start=n_node;

    return start;
}

list *add_l(list *start, int n_data)
{
    list *temp;
    list *n_node;
    temp=(list *)malloc(sizeof(list));
    n_node=(list *)malloc(sizeof(list));

    if(n_node==NULL || temp==NULL)
    {
        printf("Insufficient memory\n");
        return start;
    }

    temp=start;

    while(temp->next!=NULL)
    temp=temp->next;

    n_node->roll=n_data;
    n_node->next=temp;
    n_node->pre=temp->pre;
    temp->pre->next=n_node;
    temp->pre=n_node;
    return start;
}