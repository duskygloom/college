#include <stdio.h>

int main()
{
	int num, num_const, digit;
	long int sum, prod;
	sum = 0;
	prod = 1;
	fputs("Number: ", stdout);
	scanf("%d", &num);
	num_const = num;
	// getting each digit
	while (num > 0) {
		digit = num % 10;
		sum += digit;
		prod *= digit;
		num = num / 10;
	}
	printf("Sum: %ld\nProduct: %ld\n", sum, prod);
	return 0;
}

