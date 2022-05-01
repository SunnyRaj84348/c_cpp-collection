#include <stdio.h>
#include <stdlib.h>
struct list
{
  int roll;
  struct list *pre;
  struct list *next;
};

typedef struct list list;
list *del(list *start, int data);
list *del_f(list *start);
list *del_l(list *start);

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

  printf("\nEnter data of the node ");
  scanf("%d",&data);

  start=del(start, data);
  move=start;

  while(move!=NULL)
  {
    printf("Roll= %d\n",move->roll);
    move=move->next;
  }

}

list *del(list *start, int data)
{
  if(start->roll==data)
  {
    start=del_f(start);
    return start;
  }

  list *temp;
  temp=(list *)malloc(sizeof(list));

  if(temp==NULL)
  {
    printf("Insufficient memory");
    return start;
  }

  temp=start;

  while(temp->roll!=data)
  temp=temp->next;

  if(temp->next==NULL)
  {
    start=del_l(start);
    return start;
  }

  temp->pre->next=temp->next;
  temp->next->pre=temp->pre;
  free(temp);

  return start;
}

list *del_f(list *start)
{
  list *temp;
  temp=(list *)malloc(sizeof(list));

  if(temp==NULL)
  {
    printf("Insufficient memory");
    return start;
  }

  temp=start;
  temp->next->pre=NULL;
  start=temp->next;
  free(temp);
  return start;
}

list *del_l(list *start)
{
  list *temp;
  temp=(list *)malloc(sizeof(list));

  if(temp==NULL)
  {
    printf("Insufficient memory");
    return start;
  }

  temp=start;

  while(temp->next!=NULL)
  temp=temp->next;

  temp->pre->next=NULL;
  free(temp);
  return start;

}