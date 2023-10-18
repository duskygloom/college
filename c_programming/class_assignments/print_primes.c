#include <math.h>
#include <stdio.h>

int is_prime(int number);
void print_primes(int lower, int upper);

int main()
{
	int lower, upper;
	printf("Lower limit: ");
	scanf("%d", &lower);
	printf("Upper limit: ");
	scanf("%d", &upper);
	print_primes(lower, upper);
	return 0;
}

int is_prime(int number)
{
	// returns 1 if number is prime, else 0
	int i, root;
	root = sqrt(number);
	for (i=2; i<=root; ++i)
		if (number % i == 0) return 0;
	return 1;
}

void print_primes(int lower, int upper)
{
	// returns number of primes within lower and upper
	int i;
	printf("Primes: ");
	for (i=lower; i<=upper; ++i)
		if (is_prime(i)) printf("%d, ", i);
	printf("\b\b  \n");
}

