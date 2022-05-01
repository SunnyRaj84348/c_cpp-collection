#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(void);
void dequeue(void);
void print(void);

void main()
{
    int n;

    printf("\nEnter number of elements to be created: ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("\nQueue not created!\n");
        exit(1);
    }

    if(n > SIZE)
    {
        printf("\nValue is bigger than array size!\n");
        exit(1);
    }

    while(n--)
        enqueue();
    
    printf("\nDo you want to pop the element?");
    printf("\nEnter 1 to pop or any other key continue: ");
    scanf("%d", &n);

    if(n == 1)
    {
        printf("\nEnter number of elements to be dequeued: ");
        scanf("%d", &n);

        if(n > rear+1)
            printf("\nTotal no. of element exceeded\n");
        else
        {
            while(n--)
                dequeue();
            
            printf("\nDequeued successfully\n");
        }     
    }

    print();
}

void enqueue(void)
{
    if(rear == SIZE-1)
    {
        printf("\nQueue is full!\n");
        exit(1);
    }

    if(front == -1)
        front = 0;

    rear++;
    printf("\nEnter data: ");
    scanf("%d", &queue[rear]);
}

void dequeue(void)
{
    if(front == -1)
    {
        printf("\nQueue is empty!\n");
        exit(1);
    }
    
    if(rear == 0)
    {
        front = --rear;
    }
    else
    {
        for(int n = front; n < rear; n++)
        {
            queue[n] = queue[n+1];
        }

        rear--;
    }
}

void print(void)
{
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        exit(1);
    }

    for(int i = front; i <= rear; i++)
        printf("\n%d", queue[i]);
    
    printf("\n");
}