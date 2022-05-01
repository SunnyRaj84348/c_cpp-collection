#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
int main()
{
  struct node *start, *n1, *n2, *n3, *move;
  n1=(struct node *)malloc(sizeof(struct node));
  n2=(struct node *)malloc(sizeof(struct node));
  n3=(struct node *)malloc(sizeof(struct node));
  int i=1;
  start=n1;
  n1->next=n2;
  n2->next=n3;
  n3->next=NULL;
  move=start;
  while(move!=NULL)
  {
    printf("Enter data for %d node ", i);
    scanf("%d",&move->data);
    move=move->next;
    i++;
  }
  move=start;
  i=1;
  while(move!=NULL)
  {
    printf("\nData of %d node= %d",i,move->data);
    move=move->next;
    i++;
  }

}
