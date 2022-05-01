#include <stdio.h>

void exit();

void main()
{
    int n1,n2;
    char c;

    label1:
    printf("\nChoose operators among: \n'+' or '-' or '*' or '/' \n");

    label2:
    scanf("%c",&c);

    printf("\nEnter two operands: ");
    scanf("%d %d",&n1, &n2);

    switch(c)
    {
        case '+':
        printf("Sum = %d\n",n1+n2);
        break;

        case '-':
        printf("Difference = %d\n",n1-n2);
        break;

        case '*':
        printf("Product = %d\n",n1*n2);
        break;

        case '/':
        printf("Quotient = %d\n",n1/n2);
        break;

        default:
        printf("\nEnter correct operator: ");
        while(getchar()!='\n');
        goto label2;
    }

    printf("\nEnter 1 to continue or any other key to exit: ");
    scanf("%d",&n1);

    if(n1==1)
    {
        //while(getchar()!='\n');
        goto label1;
    }
    else
    exit(0);
}