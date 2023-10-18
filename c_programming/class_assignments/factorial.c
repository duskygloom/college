#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n, i;

	if (argc > 1)
		n = atoi(argv[1]);
	else {
		printf("Number: ");
		scanf("%d", &n);
	}

	int factorial = 1;
	for (i=2; i<=n; i+=1)
		factorial *= i;

	printf("Factorial of %d: %d\n", n, factorial);
	return 0;
}

