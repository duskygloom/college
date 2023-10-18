// square of numbers whose lsd is 5

#include <stdio.h>

int main()
{
	int n, i;
	printf("Number of inputs: ");
	scanf("%d", &n);
	putchar('\n');
	int numbers[n];
	printf("Numbers: ");
	for (i=0; i<n; ++i) {
		scanf("%d", numbers+i);
		if (numbers[i] % 10 == 5)
			printf("%d ^ 2 = %d\n", numbers[i], numbers[i]*numbers[i]);
	}
	return 0;
}

