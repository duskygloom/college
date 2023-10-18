#include <stdio.h>

int main()
{
	int n, preserved, digit, reversed;
	printf("Number: ");
	scanf("%d", &n);
	preserved = n;

	reversed = 0;

	while (n != 0) {
		digit = n % 10;
		n = n / 10;
		reversed = (10 * reversed) + digit;
	}

	printf("Reverse of %d: %d\n", preserved, reversed);
	return 0;
}

