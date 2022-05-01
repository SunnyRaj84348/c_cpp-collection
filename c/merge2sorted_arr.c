#include <stdio.h>

int main() {
    int arr1[4] = {1, 3, 7, 9};
    int arr2[4] = {2, 5, 10, 11};
    int arr3[8];

    int i = 0, j = 0, k = 0;

    while(i < 4 && j < 4) {
        if(arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    if(i == 4) {
        while(k < 8) {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }
    else {
        while(k < 8) {
            arr3[k] = arr2[i];
            i++;
            k++;
        }
    }
    
    for(int i = 0; i < 8; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}