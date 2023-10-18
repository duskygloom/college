#include <stdio.h>
#include <math.h>

int main()
{
	int num, i, j;
	printf("Number: ");
	scanf("%d", &num);
	// creating sieve
	int sieve[num];
	for (i=0; i<num; ++i) sieve[i] = 0;
	sieve[0] = sieve[1] = 1;
	for (i=2; i<num; ++i) {
		if (!sieve[i]) {
			for (j=i+i; j<num; j+=i)
				sieve[j] = 1;
		}
	}
	// finding sum
	for (i=2; i<(int)sqrt(num)+1; ++i) {
		if (!sieve[i]) {
			for (j=i; j<num; ++j) {
				if (!sieve[j]) {
					if (i + j == num) {
						printf("%d = %d + %d\n", num, i, j);
						return 0;
					}
				}
			}
		}
	}
	printf("%d cannot be expressed as sum of two prime numbers.\n", num);
	return 0;
}

