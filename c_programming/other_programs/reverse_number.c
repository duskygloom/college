#include <stdio.h>

int main()
{
	int num, num_const, num_rev;
	fputs("Number: ", stdout);
	scanf("%d", &num);
	num_const = num;
	num_rev = 0;
	while (num > 0) {
		num_rev = 10 * num_rev + (num % 10);
		num = num / 10;
	}
	printf("Reverse: %d\n", num_rev);
	return 0;
}

