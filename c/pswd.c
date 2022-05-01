#include <stdio.h>
#include <string.h>

int main() {
    char password[32];

    printf("Enter password: ");
    scanf("%s", password);

    for(int i = 0, n = 12; i < strlen(password); i++) {
        password[i] += n++;
    }

    /*for(int i = 0, n = 12; i < strlen(password); i++) {
        password[i] -= n++;
    }*/

    printf("%s\n", password);

    return 0;
}