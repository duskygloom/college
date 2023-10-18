#include <stdio.h>

void print_fibonacci(long int a, long int b, int count);

int main()
{
	int count;
	printf("Number of fibonacci: ");
	scanf("%d", &count);
	printf("Fibonacci series: ");
	print_fibonacci(0, 1, count);
	printf("\n");
	return 0;
}

void print_fibonacci(long int a, long int b, int count)
{
	static int counter = 0;
	if (counter >= count) return;
	printf("%ld ", a);
	++counter;
	print_fibonacci(b, a+b, count);
}

