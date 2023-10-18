#include <stdio.h>

void gcd_recursive(int a, int b);

int gcd(int m, int n)
{
	if (m % n == 0) return n;
	else return gcd(n, m % n);
}

int main()
{
	int a, b;
	printf("A B: ");
	scanf("%d %d", &a, &b);
	gcd_recursive(a, b);
	int value = gcd(a, b);
	printf("Sir's solution: %d\n", value);
	return 0;
}

void gcd_recursive(int a, int b)
{
	if (a % b == 0)
		printf("%d is the GCD.\n", b);
	else
		gcd_recursive(b, a % b);
}

