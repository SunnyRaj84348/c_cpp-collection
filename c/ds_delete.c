#include <stdio.h>
#include <stdlib.h>
struct node
{
  int roll;
  struct node *pre;
  struct node *next;
};
typedef struct node list;
list *del(list *start);
void main()
{
  list *start, *n1, *n2, *n3,*n4,*move;
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
  n2->pre=n1;
  n2->next=n3;
  printf("Enter roll ");
  scanf("%d",&n3->roll);
  n3->pre=n2;
  n3->next=n4;
  printf("Enter roll ");
  scanf("%d",&n4->roll);
  n4->pre=n3;
  // deletion of last node
  start=del(start);
  move=start;
  while(move!=NULL)
  {
    printf("\nRoll= %d",move->roll);
    move=move->next;
  }

}
list *del(list *start)
{
  list *ptr;
  ptr=(list *)malloc(sizeof(list));
  if(ptr==NULL)
  {
    printf("Insufficient memory");
    return start;
  }
  ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->pre->next=NULL;
  ptr->pre=NULL;
  return start;
}
