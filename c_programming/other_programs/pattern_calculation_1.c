#include <stdio.h>

int main()
{
	int num, i;
	float sum = 0;
	fputs("Number: ", stdout);
	scanf("%d", &num);
	for (i=1; i<=num; ++i)
		sum += 1.0 / i;
	printf("Result = %.2f\n", sum);
	return 0;
}

