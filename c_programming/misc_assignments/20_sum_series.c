// sum of another series

#include <stdio.h>

long power(int base, int expo);
long factorial(int num);

int main()
{
	int x, n, i;
	double sum = 0.0;
	printf("x n: ");
	scanf("%d %d", &x, &n);
	// adding and subtracting seperately to avoid 
	// checking odd or even term
	for (i=1; i<=2*n-1; i+=4)
		sum += (double)power(x, i) / factorial(i);
	for (i=3; i<=2*n-1; i+=4)
		sum -= (double)power(x, i) / factorial(i);
	printf("Sum = %lf\n", sum);
	return 0;
}

long factorial(int num)
{
	long value = 1;
	for (; num > 1; --num)
		value *= num;
	return value;
}

long power(int base, int expo)
{
	long value = 1;
	for (; expo > 0; --expo)
		value *= base;
	return value;
}

