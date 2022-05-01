#include <stdio.h>

void exit(int a);

void main() {
    FILE* file;
    char str[9];

    file = fopen("file2.txt", "w");

    if(file == NULL) {
        printf("\nFile can't be opened!\n");
        exit(1);
    }

    printf("\nEnter your name: ");

    for(int i =0; i < 9; i++) {
        scanf("%c", &str[i]);
    }

    fputs(str, file);
}