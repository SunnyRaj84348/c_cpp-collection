#include <stdio.h>
#include <math.h>

int is_as(int n);

int main() {
    int n;

    scanf("%d", &n);

    if(is_as(n))
        printf("\n%d is an armstrong number", n);
    else
        printf("\n%d is not an armstrong number", n);

    return 0;
}

int is_as(int n) {
    int n2 = n, rem, sum = 0;

    while(n > 0) {
        rem = n%10;
        sum = sum + (rem*rem*rem);
        n /= 10;
    }

    if(sum == n2)
        return 1;
    else
        return  0;
}