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

void main()
{
    list *start, *n1, *n2, *n3, *move;
    int data;
    start=(list *)malloc(sizeof(list));
    n1=(list *)malloc(sizeof(list));
    n2=(list *)malloc(sizeof(list));
    n3=(list *)malloc(sizeof(list));
    move=(list *)malloc(sizeof(list));

    if(start==NULL || n1==NULL || n2==NULL || n3==NULL || move==NULL)
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

    printf("Enter data of new node ");
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
    list *n_node;
    n_node=(list *)malloc(sizeof(list));

    if(n_node==NULL)
    {
        printf("Insufficient memory");
        return start;
    }

    n_node->roll=data;
    n_node->next=start;
    start->pre=n_node;
    start=n_node;

    return start;

}