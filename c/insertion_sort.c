#include <stdio.h>
#include <stdlib.h>

void main() {
    int *arr, j, n, key;

    printf("\nEnter no. of elements to create: ");
    scanf("%d", &n);

    if( !(arr = (int*)malloc(n*sizeof(int))) ) {
        printf("\nOut of memory!\n");
        exit(1);
    }

    arr = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) {
        printf("\nEnter data of %d element: ", i);
        scanf("%d", arr+i);
    }

    for(int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\nSorted data: ");

    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    free(arr);
}