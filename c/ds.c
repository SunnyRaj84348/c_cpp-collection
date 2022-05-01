#include <stdio.h>
#include <stdlib.h>
struct node
{
  int roll;
  char nm[20];
  struct node *next;
};
typedef struct node list;
void main()
{
  int i;
  list *start,node1,node2,node3;
  start=(list *)malloc(sizeof(list));
  start=&node1;
  printf("Enter name ");
  scanf("%s",node1.nm);
  printf("Enter roll ");
  scanf("%d",&node1.roll);
  node1.next=&node2;
  printf("Enter name ");
  scanf("%s",node2.nm);
  printf("Enter roll ");
  scanf("%d",&node2.roll);
  node2.next=&node3;
  printf("Enter name ");
  scanf("%s",node3.nm);
  printf("Enter roll ");
  scanf("%d",&node3.roll);

  for(i=0; i<3; i++)
  {
    printf("\n%d",start->roll);
    printf("\n%s",start->nm);
    start=start->next;
  }
}
