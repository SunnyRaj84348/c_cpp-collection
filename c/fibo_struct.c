#include <stdio.h>
#include <stdlib.h>

struct fibo {
    int n, n1, n2;
};

void read(struct fibo* f);
void fibo(struct fibo* f);

void main() {
    struct fibo* f;

    f = (struct fibo*)malloc(sizeof(struct fibo));

    read(f);
    fibo(f);
}

void read(struct fibo* f) {
    printf("\nEnter n number of terms: ");
    scanf("%d", &f->n);
}

void fibo(struct fibo* f) {
    int temp;

    f->n1 = 0;
    f->n2 = 1;

    for(int i = 1; i <= f->n; i++) {
        printf("%d", f->n1);

        if(i != f->n)
            printf(", ");
        
        temp = f->n1 + f->n2;
        f->n2 = f->n1;
        f->n1 = temp;
    }

    printf("\n");
}