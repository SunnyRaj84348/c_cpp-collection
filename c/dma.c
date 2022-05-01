#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, n2, i, *ptr;

  printf("Enter number of integer to be entered ");
  scanf("%d",&n);

  ptr= (int *)calloc(n,sizeof(int));
  if(ptr==NULL)
  {
    printf("Out of memory");
    exit(1);
  }

  for(i=0; i<n; i++)
  {
    printf("Enter integer ");
    scanf("%d",ptr+i);
  }

  printf("Enter no. of integer to be entered again");
  scanf("%d",&n2);

  ptr= (int *)realloc(ptr,(n+n2)*sizeof(int));

  for(i=n; i<n+n2; i++)
  {
    printf("Enter integer again");
    scanf("%d",ptr+i);
  }

  for(i=0; i<n+n2; i++)
    printf("%d ", *(ptr+i));
    free(ptr);
}
