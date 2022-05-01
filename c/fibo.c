#include <stdio.h>

void main() {
	int n, n1=0, n2=1, temp;

	printf("\nEnter the number till series is required: ");
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		printf("%d ", n1);

		temp = n1 + n2;
		n2 = n1;
		n1 = temp;
	}

	printf("\n");
}