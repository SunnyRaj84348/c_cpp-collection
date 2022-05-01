#include <stdio.h>
#include <stdlib.h>

void dec2bin(int n);

int main() {
    int n;

    printf("\nEnter decimal number: ");
    scanf("%d", &n);

    dec2bin(n);

    return 0;
}

void dec2bin(int n) {
    int *arr;
    int nm = 0;
    int tmp = n;

    // store number of blocks to allocate
    while(tmp != 0) {
        tmp = tmp / 2;
        nm++;
    }

    // allocate memory and store addrs to arr
    arr = (int*)malloc(nm * sizeof(int));

    // store remainder into array
    for(int i = nm-1; i >= 0; i--) {
        arr[i] = n % 2;
        n = n / 2;
    }

    printf("\nBinary Number:\n");

    for(int i = 0; i < nm; i++)
        printf("%d ", arr[i]);
    
    printf("\n");

    free(arr);
}