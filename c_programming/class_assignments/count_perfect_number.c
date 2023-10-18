#include <stdio.h>
#include <math.h>

int get_factor_sum(int num);

int main()
{
	int lower, upper, i, counter;
	printf("Lower limit: ");
	scanf("%d", &lower);
	printf("Upper limit: ");
	scanf("%d", &upper);
	counter = 0;
	for (i=lower; i<=upper; ++i) {
		if (get_factor_sum(i) == i)
			++counter;
	}
	printf("There are %d perfect numbers.\n", counter);
	return 0;
}

int get_factor_sum(int num)
{
	if (num == 1)
		return 0;
	int sum, i;
	int root_floor = sqrt(num);
	sum = 1;
	for (i=2; i<=root_floor; ++i) {
		if (num % i == 0)
			sum += i + (num / i);
	}
	return sum;
}

