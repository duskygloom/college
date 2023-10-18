#include <stdio.h>

int main()
{
	int a, b, i, bigger;
	printf("Number A: ");
	scanf("%d", &a);
	printf("Number B: ");
	scanf("%d", &b);

	// bigger number
	if (a > b) bigger = a;
	else bigger = b;

	int lcm = bigger;
	while (1) {
		if (lcm%a==0 && lcm%b==0) break;
		else lcm += bigger;
	}

	printf("LCM of %d and %d: %d\n", a, b, lcm);
	return 0;
}

