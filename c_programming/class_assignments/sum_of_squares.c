#include <stdio.h>

int main(void)
{
	int n, i;
	printf("Last number: ");
	scanf("%d", &n);
	int value = 0;
	for (i=0; i<n+1; i+=1)
		value += i*i;
	printf("Sum of squares: %d\n", value);
	return 0;
}

