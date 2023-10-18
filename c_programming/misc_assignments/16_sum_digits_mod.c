// finding the remainder of sum of digits by 11

#include <stdio.h>

#define MOD_VALUE 11

int main()
{
	int num, num_copy, sum_digits = 0;
	printf("Number: ");
	scanf("%d", &num);
	while (num != 0) {
		// extracting ones digit
		sum_digits += num % 10;
		num /= 10;
	}
	printf("Result = %d\n", sum_digits % 11);
	return 0;
}

