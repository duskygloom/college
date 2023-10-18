#include <stdio.h>

int gcd(int dvdend, int dvsor);

int main()
{
	int a, b;
	printf("Number A: ");
	scanf("%d", &a);
	printf("Number B: ");
	scanf("%d", &b);	
	printf("GCD of %d and %d: %d\n", a, b, gcd(a, b));
	return 0;
}

int gcd(int dvdend, int dvsor)
{
	int gcd = dvsor;
	int rmder = dvdend % dvsor;

	while (rmder != 0) {
		rmder = dvdend % dvsor;
		dvdend = dvsor;
		gcd = dvsor;
		dvsor = rmder;
	}

	return gcd;
}

