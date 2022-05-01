#include <stdio.h>
#include <stdlib.h>
void main()
{
  int n,*arr, i;
  printf("\nEnter total number of element ");
  scanf("%d",&n);
  arr=(int *)calloc(n, sizeof(int));

  if(arr==NULL)
  {
    printf("Insufficient memory");
    exit(1);
  }

  printf("Enter numbers ");

  for(i=0; i<n; i++)
    scanf("%d",&arr[i]);

  for(i=0; i<n; i++)
  printf("\n%d",arr[i]);
  
  printf("\n");

  free(arr);
}
