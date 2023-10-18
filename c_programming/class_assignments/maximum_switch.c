#include <stdio.h>

int main()
{
	int a, b, a_greater;
	printf("A B: ");
	scanf("%d %d", &a, &b);
	a_greater = a > b;
	if (a_greater) printf("%d is greater.", a);
	else printf("%d is greater.", b);
	return 0;
}

