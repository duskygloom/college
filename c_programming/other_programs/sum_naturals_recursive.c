#include <stdio.h>

int sum_naturals(int num);

int main()
{
	int num;
	printf("Number: ");
	scanf("%d", &num);
	printf("Result: %d\n", sum_naturals(num));
	return 0;
}

int sum_naturals(int num)
{
	if (num < 1) return 0;
	return num + sum_naturals(num - 1);
}

