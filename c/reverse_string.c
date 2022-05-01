#include <stdio.h>
#include <string.h>

char* reverse(char* str) {
    size_t size = strlen(str);

    for(int i = 0; i < size/2; i++) {
        int temp = str[i];
        str[i] = str[size-(i+1)];
        str[size-(i+1)] = temp;
    }

    return str;
}

int main() {
    char nm[25];

    printf("\nEnter your name: ");
    scanf("%s", nm);

    printf("\n%s", reverse(nm));

    return 0;
}