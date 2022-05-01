#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* inp_str() {
    char nm[100];
    char* ptr = NULL;

    fgets(nm, 100, stdin);
    nm[strlen(nm)-1] = '\0';

    ptr = (char*)malloc(strlen(nm));
    strcpy(ptr, nm);

    return ptr;
}

int main() {
    char* ptr = NULL;
    int count = 0;

    printf("Enter name: ");
    ptr = inp_str();

    for(int i = 0; i < strlen(ptr); i++) {
        if(i == 0 || ptr[i-1] == ' ' || ptr[i+1] == ' ' || ptr[i+1] == '\0')
            ptr[i] -= 32;
    }

    printf("%s", ptr);

    return 0;
}