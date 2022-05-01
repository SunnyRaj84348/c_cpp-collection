#include <stdio.h>
#include <stdlib.h>
struct node
{
  int roll;
  struct node *next;
};
typedef struct node list;
list *fun(list *start, int data);
void main()
{
  int i=1, data;
  list *start,*node1,*node2,*node3,*move;
  start=(list *)malloc(sizeof(list));
  node1=(list *)malloc(sizeof(list));
  node2=(list *)malloc(sizeof(list));
  node3=(list *)malloc(sizeof(list));
  if(start==NULL || node1==NULL || node2==NULL || node3==NULL)
  {
    printf("Insufficient memory");
    exit(1);
  }
  start=node1;
  printf("Enter roll ");
  scanf("%d",&node1->roll);
  node1->next=node2;
  printf("Enter roll ");
  scanf("%d",&node2->roll);
  node2->next=node3;
  printf("Enter roll ");
  scanf("%d",&node3->roll);

  printf("Enter roll for new first node");
  scanf("%d",&data);
  start=fun(start,data);
  move=start;

  while(move!=NULL)
  {
    printf("\nRoll of %d node= %d",i,move->roll);
    move=move->next;
    i++;
  }


}
list *fun(list *start, int data)
{
  list *new;
  new=(list *)malloc(sizeof(list));
  if(new==NULL)
  {
    printf("Insufficient memory");
    return start;
  }
  new->roll=data;
  new->next=start;
  start=new;
  return start;
}
