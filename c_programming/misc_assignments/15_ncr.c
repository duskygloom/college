// nCr calculator

#include <stdio.h>

int ncr(int n, int r);

int main()
{
	int n, r;
	printf("n r: ");
	scanf("%d %d", &n, &r);
	printf("nCr = %d\n", ncr(n, r));
	return 0;
}

int ncr(int n, int r)
{
	int value = 1, i;
	if (n-r > r) r = n - r;
	// nCr = n * n-1 * n-2 ... r / n-r / n-r-1 / n-r-2 ... 1
	for (i=n; i>r; --i) 
		value *= i;
	for (i=1; i<=n-r; ++i) 
		value /= i;
	return value;
}

