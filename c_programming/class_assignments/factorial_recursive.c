#include <stdio.h>

long int factorial(int n);

int main()
{
	int n;
	printf("Number: ");
	scanf("%d", &n);
	printf("Factorial of number: %ld\n", factorial(n));
	return 0;
}

long int factorial(int n)
{
	if (n <= 1) return 1;
	return n * factorial(n-1);
}

