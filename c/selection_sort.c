#include <stdio.h>
#include <stdlib.h>

void main() {
    int *arr, min, n, temp;

    printf("\nEnter no. of elements to create: ");
    scanf("%d", &n);

    if( !(arr = (int*)malloc(n*sizeof(int))) ) {
        printf("\nOut of memory!\n");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        printf("\nEnter data of %d element: ", i);
        scanf("%d", arr+i);
    }

    for(int i = 0; i < n-1; i++) {
        min = i;

        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nSorted data: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    free(arr);
}