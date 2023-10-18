#include <stdio.h>

int main()
{
	int n, r, i, combination;
	printf("N r: ");
	scanf("%d %d", &n, &r);

	combination = 1;

	for (i=n; i>(n-r); --i)
		combination *= i;

	for (i=r; i>1; --i)
		combination /= i;

	printf("Combination: %d\n", combination);
	return 0;
}

