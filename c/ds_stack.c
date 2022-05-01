#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack
{
    int arr[SIZE];
    int top;
};

typedef struct stack st;

int isfull(st* s);
int isempty(st* s);
void push(st* s);
void pop(st* s);
void print(st* s);

void main()
{
    st *s = (st*)malloc(sizeof(st));

    s->top = -1;

    int n;

    printf("\nEnter number of element to be created: ");
    scanf("%d", &n);

    if(n == 0)
    {
        printf("\nStack not created!\n");
        exit(1);
    }

    while(n--)
        push(s);

    printf("\nDo you want to pop the element?");
    printf("\nEnter 1 to pop or any other key continue: ");
    scanf("%d", &n);

    if(n == 1)
    {
        printf("Enter the total no. of elements you want to pop: ");
        scanf("%d", &n);

        if(n > s->top+1)
            printf("\nTotal no. of elements exceeded!\n");
        else
            while(n--)
                pop(s);
    }

    print(s);
}

int isfull(st* s)
{
    if(s->top == SIZE-1)
        return 1;
    else
        return 0;
}

int isempty(st* s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

void push(st* s)
{
    if(isfull(s))
    {
        printf("\nStack full\n");
        exit(0);
    }

    s->top++;

    printf("\nEnter data: ");
    scanf("%d", &s->arr[s->top]);
}

void pop(st* s)
{
    if(isempty(s))
    {
        printf("\nStack empty\n");
        exit(0);
    }
    
    s->top--;
}

void print(st* s)
{
    int i;

    for(i = 0; i <= s->top; i++)
    {
        printf("\nData = %d", s->arr[i]);
    }

    printf("\n");
}