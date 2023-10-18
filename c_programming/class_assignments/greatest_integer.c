#include <stdio.h>

int main(void)
{
	int n, i, greatest, integer;
	printf("Number of integers: ");
	scanf("%d", &n);
	printf("\n");

	if (n < 1) {
		printf("No integers recieved.\n");
		return 0;
	}

	printf("1) Integer: ");
	scanf("%d", &greatest);

	for (i=2; i<n+1; i+=1) {
		printf("%d) Integer: ");
		scanf("%d", &integer);
		if (integer > greatest)
			greatest = integer;
	}

	printf("\nMaximum integer: %d\n", greatest);
	return 0;
}

