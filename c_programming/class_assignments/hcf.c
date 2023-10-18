#include <stdio.h>

int main()
{
	int a, b, i, smaller;
	printf("Number A: ");
	scanf("%d", &a);
	printf("Number B: ");
	scanf("%d", &b);

	// setting the smaller number
	if (a < b) smaller = a;
	else smaller = b;

	int hcf = 1;
	for (i=smaller; i>1; i-=1) {
		if (a%i==0 && b%i==0) {
			hcf = i;
			break;
		}
	}

	printf("HCF of %d and %d: %d\n", a, b, hcf);

	return 0;
}

