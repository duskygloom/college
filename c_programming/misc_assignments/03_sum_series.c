// print sum of a series

#include <stdio.h>

int power(int base, int super);
int factorial(int num);

int main()
{
	int x, i;
	double result = 1.0;
	printf("Value of x: ");
	scanf("%d", &x);
	if (x >= 2) {
		for (i=2; i<=x; i+=2)
			result += (double)power(x, i) / (double)factorial(i);
		for (i=3; i<=x; i+=2)
			result -= (double)power(x, i) / (double)factorial(i);
	}
	printf("Value = %lf\n", result);
	return 0;
}

int power(int base, int super)
{
	int value = 1;
	for (; super>0; --super)
		value *= base;
	return value;
}

int factorial(int num)
{
	int value = 1;
	for (; num>1; --num)
		value *= num;
	return value;
}

