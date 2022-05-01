#include <stdio.h>
#include <stdlib.h>
struct list
{
  int roll;
  struct list *pre;
  struct list *next;
};
struct list *rep(struct list *start, int data);
void main()
{
  struct list *start, *n1, *n2, *n3, *move;
  int data;
  start=(struct list *)malloc(sizeof(struct list));
  n1=(struct list *)malloc(sizeof(struct list));
  n2=(struct list *)malloc(sizeof(struct list));
  n3=(struct list *)malloc(sizeof(struct list));
  move=(struct list *)malloc(sizeof(struct list));

  if(start==NULL || n1==NULL || n2==NULL || n3==NULL || move==NULL)
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
  n2->pre=n1;
  n2->next=n3;
  printf("Enter roll ");
  scanf("%d",&n3->roll);
  n3->pre=n2;

  printf("Enter roll of existing node to be replaced ");
  scanf("%d",&data);
  start=rep(start,data);
  move=start;
  while(move!=NULL)
  {
    printf("Roll= %d\n",move->roll);
    move=move->next;
  }

}
struct list *rep(struct list *start, int data)
{
  struct list *temp;
  temp=(struct list *)malloc(sizeof(struct list));
  if(temp=NULL)
  {
    printf("Insufficient memory");
    return start;
  }
  temp=start;
  while(temp->roll!=data)
  {
    temp=temp->next;
  }
  printf("Enter new data to replace ");
  scanf("%d",&temp->roll);
  return start;
}
