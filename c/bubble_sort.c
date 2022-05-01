#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, n, temp;

    printf("\nEnter no. of blocks of array to create: ");
    scanf("%d", &n);

    if( !(arr = (int*)malloc(n*sizeof(int))) )
        printf("\nOut of memory!");

    for(int i = 0; i < n; i++) {
        printf("\nEnter data of %d element: ", i);
        scanf("%d", arr+i);
    }

    int c = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

            c++;
        }
    }

    /*for(int i = 0; i < n; i++) {
        printf("\nData = %d", arr[i]);
    }*/

    printf("\n\n%d", c);

    printf("\n");
}