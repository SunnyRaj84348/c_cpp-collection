#include <stdio.h>
#include <stdbool.h>

void main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l = 0, r = 9;
    int m, n;
    bool f = false;
    
    printf("\nEnter data to search: ");
    scanf("%d", &n);

    while(l <= r) {
        m = (l+r)/2;

        if(n < arr[m])
            r = m-1;
        else if(n > arr[m])
            l = m+1;
        else {
            printf("\nData founded");
            f = !f;
            break;
        }
    }

    if(!f)
        printf("\nData not founded!");
}