#include <stdio.h>

int main()
{
	int n, preserved, digit, sum;
	printf("Number: ");
	scanf("%d", &n);
	preserved = n;

	sum = 0;

	while (n != 0) {
		digit = n % 10;
		sum += digit;
		n /= 10;
	}

	printf("Sum of all digits of %d: %d\n", preserved, sum);
	return 0;
}

