#include <stdio.h>
#define MAX_VALUE 1000

int main()
{
	int i;
	double value;
	value = 1.0;
	for (i=2; i<=MAX_VALUE; ++i) {
		if (i%2 == 0) value -= (1.0 / i);
		else value += (1.0 / i);
	}
	printf("Value from for loop: %lf\n", value);

	value = 1.0;
	i = 2;
	while (i <= MAX_VALUE) {
		if (i%2 == 0) value -= (1.0 / i);
		else value += (1.0 / i);
		++i;
	}
	printf("Value from while loop: %lf\n", value);

	value = 1.0;
	i = 2;
	do {
		if (i%2 == 0) value -= (1.0 / i);
		else value += (1.0 / i);
		++i;
	} while (i < 1000);
	printf("Value from do-while loop: %lf\n", value);
	return 0;
}

