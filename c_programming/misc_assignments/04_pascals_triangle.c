// print Pascal's triangle

#include <stdio.h>

int ncr(int n, int r);

int main()
{
	int i, j, n;
	printf("Number of lines: ");
	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		for (j=0; j<n-i-1; ++j) putchar(' ');
		for (j=0; j<i+1; ++j) printf("%d ", ncr(i, j));
		putchar('\n');
	}
	return 0;
}

int ncr(int n, int r)
{
	int i, value = 1;
	r = n-r > r ? n-r : r;
	for (i=n; i>r; --i) value *= i;
	for (i=n-r; i>1; --i) value /= i;
	return value;
}

