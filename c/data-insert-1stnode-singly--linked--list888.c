//program of inserting at 1st node in singly linked list.....
#include<stdio.h>
#include<malloc.h>

struct node
{
	int roll;
	char nm[20];
	struct node *next;
	
};
typedef struct node list;

list *insert_new(list *);

 
int main()
{

 list *start, *node1, *node2, *node3, *move;

 start=(struct node*)malloc(sizeof(list));
 node1=(struct node*)malloc(sizeof(list));
 node2=(struct node*)malloc(sizeof(list));
 node3=(struct node*)malloc(sizeof(list));
 move=(struct node*)malloc(sizeof(list));

 start=node1;

 printf("\n enter roll ");
 scanf("%d",&node1->roll);
 printf("Enter name: ");
 gets(node1->nm);
 node1->next=node2;
 
 printf("\n enter roll ");
 scanf("%d",&node2->roll);
 printf("Enter name: ");
 gets(node2->nm);
 node2->next=node3;
 
 printf("\n enter roll ");
 scanf("%d",&node3->roll);
 printf("Enter name: ");
 gets(node3->nm);
 node3->next=NULL;

 // takinf a loop for moving the node
 start=insert_new(start);
 move=start;
 while(move!=NULL)
 { printf("%d",move->roll);
   puts(start->nm);
   move=move->next;
 }

}
 struct node *insert_new(struct node *start)
 { 
    struct node *new_node;
    int num;
    // allocate memory space for new node....
    new_node=(struct node*)malloc(sizeof(struct node));

    printf("Enter roll for new node: ");
    scanf("%d",&num);

    printf("Enter name: ");
    gets(new_node->nm);

   new_node->roll=num;
   new_node->next=start;
   start=new_node;

      return start;
 }
