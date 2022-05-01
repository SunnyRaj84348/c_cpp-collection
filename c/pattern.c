#include <stdio.h>

int main() {
    int n, k;

    printf("\nEnter no. of columns: ");
    scanf("%d", &n);

    for(int i = 0; i < (n+1)/2; i++) {
        k = 0;

        for(int j = 0; j < n; j++) {
            if(j == ((n+1)/2)-i)
                k = (i*2)-1;

            if(i && k) {
                printf(" ");
                k--;
                continue;
            }
            printf("*");
        }

        printf("\n");
    }

    return 0;
}