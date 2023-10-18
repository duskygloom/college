#include <stdio.h>
#include <math.h>

int get_factor_sum(int num);

int main()
{
	int num;
	printf("Number: ");
	scanf("%d", &num);
	if (get_factor_sum(num) == num)
		printf("%d is a perfect number.\n", num);
	else
		printf("%d is not a perfect number.\n", num);
	return 0;
}

int get_factor_sum(int num)
{
	int sum, i;
	int root_floor = sqrt(num);
	sum = 1;
	for (i=2; i<=root_floor; ++i) {
		if (num % i == 0)
			sum += i + (num / i);
	}
	return sum;
}

