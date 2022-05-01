#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
    char name[50];
    unsigned long long ac_number;
    long long balance;
};

void printName(struct account* ptr, size_t n) {
    printf("\nCustomers having balance less than $200 -\n");

    for(int i = 0; i < n; i++) {
        if(ptr[i].balance < 200)
            printf("%s", ptr[i].name);
    }
}

void incr(struct account* ptr, size_t n) {
    printf("\nIncremented balance of customers -\n");

    for(int i = 0; i < n; i++) {
        if(ptr[i].balance > 1000) {
            ptr[i].balance += 100;
            printf("\n%s : %lld", ptr[i].name, ptr[i].balance);
        }
    }
}

int main() {
    size_t n;
    struct account* var;

    printf("\nEnter total number of customers: ");
    scanf("%zu", &n);

    var = (struct account*)malloc(n * sizeof(struct account));

    if(var ==  NULL) {
        printf("\nOut of memory\n");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        // Clear input buffer
        while(getchar() != '\n');

        printf("\nEnter name: ");
        fgets(var[i].name, 50, stdin);

        printf("\nEnter account number: ");
        scanf("%llu", &var[i].ac_number);

        printf("\nEnter balance: ");
        scanf("%lld", &var[i].balance);

        printf("\n");
    }

    for(int i = 0; i < n; i++) {
        var[i].name[strlen(var[i].name) - 1] = '\0';
    }

    printName(var, n);
    incr(var, n);

    return 0;
}