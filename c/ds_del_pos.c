#include <stdio.h>
#include <stdlib.h>
struct list
{
  int roll;
  struct list *next;
};
typedef struct list list;
list *del_pos(list *start);
list *del_f(list *start);
list *del_l(list *start);
void main()
{
  list *start, *n1, *n2, *n3, *n4, *move;
  start=(list *)malloc(sizeof(list));
  n1=(list *)malloc(sizeof(list));
  n2=(list *)malloc(sizeof(list));
  n3=(list *)malloc(sizeof(list));
  n4=(list *)malloc(sizeof(list));

  if(start==NULL || n1==NULL || n2==NULL || n3==NULL || n4==NULL)
  {
    printf("Insufficient memory");
    exit(1);
  }

  start=n1;
  printf("Enter roll ");
  scanf("%d",&n1->roll);
  n1->next=n2;
  printf("Enter roll ");
  scanf("%d",&n2->roll);
  n2->next=n3;
  printf("Enter roll ");
  scanf("%d",&n3->roll);
  n3->next=n4;
  printf("Enter roll ");
  scanf("%d",&n4->roll);

  start=del_pos(start);
  move=start;
  while(move!=NULL)
  {
    printf("\nRoll= %d",move->roll);
    move=move->next;
  }

}
list *del_pos(list *start)
{
  list *temp,*migrate;
  int num,count=1;
  temp=(list *)malloc(sizeof(list));
  migrate=(list *)malloc(sizeof(list));
  if(temp==NULL || migrate==NULL)
  {
    printf("Insufficient memory");
    return start;
  }
  printf("Enter position of node ");
  scanf("%d",&num);
  temp=start;

  if(num==1)
  {
    start=del_f(start);
    return start;
  }

  while(count!=num-1)
  {
    temp=temp->next;
    count=++count;
  }

  if(temp->next->next==NULL)
  {
    start=del_l(start);
    return start;
  }

  migrate=temp->next;
  temp->next=migrate->next;
  migrate->next=NULL;
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
  temp=start->next;
  start->next=NULL;
  start=temp;
  return start;
}
list *del_l(list *start)
{
  list *travel;
  travel=(list *)malloc(sizeof(list));
  if(travel==NULL)
  {
    printf("Insufficient memory");
    exit(1);
  }
  travel=start;
  while(travel->next->next!=NULL)
  travel=travel->next;

  travel->next=NULL;
  return start;
}
