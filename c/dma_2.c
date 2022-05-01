#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,i,*ptr;
  n=10;
  ptr= (int *)calloc(n,sizeof(int));
  if(ptr==NULL)
  {
    printf("Out of memory");
    exit(1);
  }
  for(i=0; i<10; i++)
  {
    printf("Enter integer ");
    scanf("%d",&ptr[i]);
  }
  
  for(i=0; i<10; i++)
    printf("%d ", *(ptr+i));
    free(ptr);

}
