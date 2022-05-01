#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *createlist(struct node*);
struct node *delnode(struct node*);

void main()
{
    struct node *start, *move;

    start = createlist(start);

    start = delnode(start);

    move = start;

    do
    {
        printf("\nData = %d", move->data);
        move = move->next;
    } while (move != start);

    printf("\n");
}

struct node *createlist(struct node* start)
{
    struct node *p, *nd;
    int data, i, n;

    nd = (struct node*)malloc(sizeof(struct node));

    if(nd == NULL)
    {
        printf("\nOut of memory");
        return start;
    }

    start = nd;
    p = start;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("\nNo node created\n");
        exit(0);
    }

    printf("\nEnter data of 1 node: ");
    scanf("%d", &start->data);

    start->next = start;

    for(i = 2; i <= n; i++)
    {
        nd = (struct node*)malloc(sizeof(struct node));

        if(nd == NULL)
        {
            printf("\nOut of memory");
            return start;
        }

        printf("Enter data of %d node: ", i);
        scanf("%d", &data);

        nd->data = data;

        while(p->next != start)
        p = p->next;

        p->next = nd;
        nd->next = start;
    }

    return start;
}

struct node *delnode(struct node* start)
{
    int n, c = 1, count = 0, f = 0;
    struct node *temp, *move=start;

    // Get total no. of nodes
    do
    {
        count++;
        move = move->next;
    } while (move != start);

    printf("\nEnter position of node to be deleted: ");
    scanf("%d", &n);

    if(n == 0 || n > count )
    {
        printf("Invalid position!\n");
        exit(1);
    }
    
    if(count == 1)
    {
        printf("\nWARNING: Only one node exist and it will be deleted!\n");
        printf("Press 0 to exit now or any other key to continue: ");
        scanf("%d", &f);

        if(f == 0)
        exit(0);
    }

    do
    {
        if(c == n)
        break;

        move=move->next;
        c++;
    } while (move != start);

    if(move == start)
    {
        while(move->next != start)
        move = move->next;

        move->next = start->next;

        temp = start;

        start = start->next;
        free(temp);

        if(f != 0)
        {
            printf("\nList is empty now\n");
            exit(0);
        }

        return start;
    }

    if(move->next == start)
    {
        temp = start;

        while(temp->next != move)
        temp=temp->next;

        temp->next = start;
        free(move);

        return start;
    }

    temp = start;

    while(temp->next != move)
    temp = temp->next;

    temp->next = move->next;
    free(move);

    return start;
}