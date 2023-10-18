// int to hexadecimal

#include <stdio.h>

#define MAX_HEXLEN sizeof(int) * 2

int main()
{
	// using unsigned int to avoid sign problems
	unsigned int number, number_preserved;
	int digit, i;
	char hex_number[MAX_HEXLEN];
	printf("Decimal number: ");
	scanf("%i", &number);
	number_preserved = number;
	for (i=MAX_HEXLEN-1; i>=0; --i) {
		digit = number % 16;
		number /= 16;
		if (digit > 9)
			hex_number[i] = digit + 'A' - 10;
		else
			hex_number[i] = digit + '0';
	}
	// printing all hex characters individually
	// because not null terminated
	printf("Hexadecimal: ");
	for (i=0; i<MAX_HEXLEN; ++i)
		putchar(hex_number[i]);
	putchar('\n');
	return 0;
}

