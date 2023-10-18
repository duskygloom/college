#include <stdio.h>

double ncr(int n, int r);
double exponent(int base, int power);

int main()
{
	int n, i;
	double sum;
	printf("n: ");
	scanf("%d", &n);
	for (i=0; i<=n; ++i)
		sum += ncr(n, i);
	printf("Sum of combinations: %.2lf\nPower of two: %.2lf\n", 
			sum, exponent(2, n));
	return 0;
}

double ncr(int n, int r)
{
	int i;
	double c = 1.0;
	for (i=0; i<r; ++i) {
		c *= n - i;
		c /= r - i;
	}
	return c;
}

double exponent(int base, int power)
{
	double value = 1.0;
	while (power > 0) {
		value *= base;
		--power;
	}
	return value;
}

