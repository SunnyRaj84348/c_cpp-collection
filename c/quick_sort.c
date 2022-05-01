#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int* arr, int l, int r) {
    int piv = l, size = r;

    while(l < r) {
        while(arr[l] <= arr[piv] && l < size)
            l++;
        
        while(arr[r] > arr[piv])
            r--;
        
        if(l < r)
            swap(arr+l, arr+r);
    }

    swap(arr+r, arr+piv);

    return r;
}

void sort(int* arr, int l, int r) {
    if(l < r) {
        int j = part(arr, l, r);
        sort(arr, l, j-1);
        sort(arr, j+1, r);
    }
}

int main() {
    int *arr, n;

    printf("\nEnter total no. of elements: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    if(!arr) {
        printf("\nOut of memory!\n");
        exit(1);
    }

    printf("\nEnter array data: ");
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);

    sort(arr, 0, n-1);

    printf("\nArray: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}