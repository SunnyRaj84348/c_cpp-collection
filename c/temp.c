#include <stdio.h>

int pqr(int, int);

int main() {
    int x = pqr(20, 2);

    printf("\n%d", x);

    return 0;
}

int pqr(int x, int y) {
    if(x == 0)
        return 0;
    else
        return x+pqr(x/y, y);
}