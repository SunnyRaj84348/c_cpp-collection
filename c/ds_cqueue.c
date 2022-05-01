#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int cqueue[SIZE];

int front = -1, rear = -1;

void exit(int code);

bool is_empty();
bool is_full();
void enqueue(void);
void dequeue(void);
void print(void);

/*void main()
{
	
}*/

void enqueue(void)
{
	if(is_full())
	{
		printf("\nQueue is full!\n");
		return;
	}

	if(is_empty())
		front = rear = 0;
	else if(rear == SIZE-1)
		rear = 0;
	else
		rear++;
	
	printf("\nEnter data: ");
	scanf("%d", &cqueue[rear]);
}

void dequeue(void)
{
	if(is_empty())
	{
		printf("\nQueue is empty!\n");
		exit(1);
	}

	if(front == rear)
		front = rear = -1;
	else
		front++;
}

bool is_empty() {
	if(front == -1)
		return 1;
	
	return 0;
}

bool is_full() {
	if(front == rear+1 || (front == 0 && rear == SIZE-1) )
		return 1;
	
	return 0;
}

void print(void)
{
	if(is_empty())
	{
		printf("\nQueue is empty!\n");
		exit(1);
	}

	int i = front;

	printf("\nQueue: ");
	if(front <= rear) {
		while(i <= rear)
			printf("%d ", cqueue[i++]);
	}
	else {
		while(i < SIZE)
			printf("%d ", cqueue[i++]);
		
		i = 0;

		while(i <= rear)
			printf("%d ", cqueue[i++]);
	}
		
	printf("\n");
}