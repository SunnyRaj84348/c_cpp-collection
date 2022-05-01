#include <stdio.h>
#include <stdlib.h>
struct list
{
  int roll;
  struct list *next;
};
typedef struct list list;
list *del_f(list *start);
void main()
{
  list *start, *n1, *n2, *n3, *move;
  start=(list *)malloc(sizeof(list));
  n1=(list *)malloc(sizeof(list));
  n2=(list *)malloc(sizeof(list));
  n3=(list *)malloc(sizeof(list));
  move=(list *)malloc(sizeof(list));

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
  n2->next=n3;
  printf("Enter roll ");
  scanf("%d",&n3->roll);

  start=del_f(start);
  move=start;
  while(move!=NULL)
  {
    printf("\nRoll= %d",move->roll);
    move=move->next;
  }
}
list *del_f(list *start)
{
  list *temp;
  temp=(list *)malloc(sizeof(list));
  if(temp==NULL)
  {
    printf("Insufficient memory");
    exit(1);
  }
  temp=start;
  start=start->next;
  free(temp);
  return start;
}
