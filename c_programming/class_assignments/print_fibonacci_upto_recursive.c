#include <stdio.h>

void print_fibonacci_upto(long int a, long int b, long int upper);

int main()
{
	long int upper;
	printf("Upper limit: ");
	scanf("%ld", &upper);
	printf("Fibonacci series: ");
	print_fibonacci_upto(0, 1, upper);
	printf("\n");
	return 0;
}

void print_fibonacci_upto(long int a, long int b, long int upper)
{
	if (a >= upper) return;
	printf("%ld ", a);
	print_fibonacci_upto(b, a+b, upper);
}

