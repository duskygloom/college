#include <stdio.h>

int power(int base, int pow);

int main()
{
	int base, pow;
	printf("Base: ");
	scanf("%d", &base);
	printf("Power: ");
	scanf("%d", &pow);
	printf("Result: %d\n", power(base, pow));
	return 0;
}

int power(int base, int pow)
{
	if (pow < 1) return 1;
	return base * power(base, pow - 1);
}

