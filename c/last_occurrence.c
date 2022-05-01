#include <stdio.h>

int last_occ(int* arr, size_t size, int key) {
    int low = 0, high = size-1;
    int mid;

    while(low <= high) {
        mid = (low+high)/2;

        if(arr[mid] < key)
            low = mid+1;
        else if(arr[mid] > key)
            high = low-1;
        else {
            if(mid == size-1 || arr[mid+1] != key)
                return mid;
            else
                low = mid+1;
        }
    }

    return -1;
}

int main() {
    int arr[6] = {4, 7, 10, 10, 10, 10};

    printf("%d\n", last_occ(arr, 6, 10));

    return 0;
}