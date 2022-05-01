#include <stdio.h>

void merge(int* arr, int l, int mid, int r) {
    int i = l, j = mid+1, k = l;
    static int arr2[10];

    while(i <= mid && j <= r) {
        if(arr[i] < arr[j]) {
            arr2[k] = arr[i];
            i++;
        }
        else {
            arr2[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i > mid) {
        while(j <= r) {
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    else {
        while(i <= mid) {
            arr2[k] = arr[i];
            i++;
            k++;
        }
    }

    for(k = l; k <= r; k++) {
        arr[k] = arr2[k];
    }
}

void mergesort(int* arr, int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int arr[10] = {5, 6, 3, 2, 0, 7, 9, 8, 1, 4};

    mergesort(arr, 0, 9);

    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}