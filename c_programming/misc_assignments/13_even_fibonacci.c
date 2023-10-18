// even fibonacci numbers

#include <stdio.h>

int main()
{
	int n, a = 0, b = 1, temp;
	printf("How many numbers do you need? ");
	scanf("%d", &n);
	printf("Even fibonacci numbers:");
	// fibonacci numbers: 0 1 1+0 1+1 2+1 3+2 5+3...
	while (n > 0) {
		if (a % 2 == 0) {
			printf(" %d", a);
			--n;
		}
		temp = b;
		b += a;
		a = temp;
	}
	putchar('\n');
	return 0;
}

