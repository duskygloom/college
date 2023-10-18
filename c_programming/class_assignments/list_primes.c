#include <stdio.h>

// print prime numbers <= n

int main()
{
	int n, i, j;
	printf("Number: ");
	scanf("%d", &n);

	// creating sieve of eratosthenes
	int sieve[n+1];
	sieve[0] = sieve[1] = 0;
	for (i=0; i<=n; ++i) sieve[i] = 1;

	// marking composite numbers
	for (i=2; i<n+1; ++i) {
		j = i + i;
		if (sieve[i]) {
			while (j <= n) {
				sieve[j] = 0;
				j += i;
			}
		}
	}

	// printing primes
	printf("Prime numbers: ");
	for (i=2; i<n+1; ++i)
		if (sieve[i]) printf("%d ", i);
	putchar('\n');
	return 0;
}

