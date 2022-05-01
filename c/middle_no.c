#include <stdio.h>

int main() {
	int n, count = 0, temp, mid;

	printf("\nEnter a number: ");
	scanf("%d", &n);

	temp = n;

	while(temp != 0) {
		temp /= 10;
		count++;
	}

	temp = n;

	if(count % 2 != 0) {
		count = (count+1) / 2;

		while(count--) {
			mid = temp % 10;
			temp /= 10;
		}

		printf("\nMiddle number = %d", mid);
	}
	else
		printf("\nMiddle number doesn't exist");

	return 0;
}