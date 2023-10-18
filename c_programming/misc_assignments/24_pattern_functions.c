// 2 more series sums

#include <stdio.h>

int factorial(int x);

int exponent(int base, int power);

double series_1(int x, int n);

double sin_series(int x, int n);

int main()
{
	int x, n;
	printf("x n: ");
	scanf("%d %d", &x, &n);
	printf("Series 1: %lf\nSin series: %lf\n", 
			series_1(x, n), sin_series(x, n));
	return 0;
}

int factorial(int x)
{
	int value = 1;
	while (x > 1) value *= x--;
	return value;
}

int exponent(int base, int power)
{
	int value = 1;
	while (power > 0) {
		value *= base;
		--power;
	}
	return value;
}

double series_1(int x, int n)
{
	int i;
	double result = 1.0;
	for (i=2; i<=n; i+=4) 
		result += (double)exponent(x, i) / (double)factorial(i);
	for (i=4; i<=n; i+=4) 
		result -= (double)exponent(x, i) / (double)factorial(i);
	return result;
}

double sin_series(int x, int n)
{
	int i;
	double result = 1.0;
	for (i=1; i<=n; i+=4) 
		result += (double)exponent(x, i) / (double)factorial(i);
	for (i=3; i<=n; i+=4) 
		result -= (double)exponent(x, i) / (double)factorial(i);
	return result;
}

