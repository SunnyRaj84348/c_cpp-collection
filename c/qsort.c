#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[25];
    unsigned short roll;
} Stud;

char* ordinal(int n) {
    if(n % 100 == 11 || n % 100 == 12 || n % 100 == 13)
        return "th";

    switch(n % 10) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int compare(const void* a, const void* b) {
    return ( ((Stud*)a)->roll - ((Stud*)b)->roll );
}

int main() {
    int n;
    Stud* data;

    printf("\nEnter total no. of students: ");
    scanf("%d", &n);

    data = (Stud*)malloc(n * sizeof(Stud));

    for(int i = 0; i < n; i++) {
        printf("\nEnter data of %d%s student\n", i+1, ordinal(i+1));

        getchar(); // clear input buffer

        printf("\nEnter name: ");
        fgets(data[i].name, 25, stdin);
        data[i].name[strlen(data[i].name) - 1] = '\0';

        printf("\nEnter roll: ");
        scanf("%hu", &data[i].roll);

        printf("\n");
    }

    qsort(data, n, sizeof(Stud), compare);

    for(int i = 0; i < n; i++) {
        printf("\nName = %s", data[i].name);
        printf("\tRoll = %hu", data[i].roll);
    }

    printf("\n");

    return 0;
}