#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void* p1, void* p2, size_t size) {
    void* temp = malloc(size);

    memcpy(temp, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, temp, size);

    free(temp);
}

int main() {
    int a = 5, b = 10;

    char c = 'd', d = 'e';

    swap(&c, &d, sizeof(char));
   // printf("\nSwaped data: %d and %d\n", a, b);

   printf("\n%c %c", c, d);

    return 0;
}