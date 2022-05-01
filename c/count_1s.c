#include <stdio.h>

int cnt_1s(int* arr, size_t size) {
    int low = 0, high = size-1;
    int mid, cnt = 0;

    while(low <= high) {
        mid = (low+high)/2;

        if(arr[mid] > 1)
            high = mid-1;
        else if(arr[mid] < 1)
            low = mid+1;
        else {
            if(arr[mid-1] != 1) {
                while(arr[mid] == 1 && mid < size) {
                    cnt++;
                    mid++;
                }
                
                return cnt;
            }
            else if(arr[mid+1] != 1) {
                while(arr[mid] == 1 && mid >= 0) {
                    cnt++;
                    mid--;
                }
                
                return cnt;
            }
            else {
                high = mid-1;
            }
        }
    }

    return 0;
}

int main() {
    int arr[] = {0, 0, 0, 1, 1, 1, 2, 2};

    printf("%d\n", cnt_1s(arr, 8));

    return 0;
}