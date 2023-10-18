// a function of x which is different for different values of d

#include <stdio.h>

int main()
{
	int a, b, c, d, x, fx, i;
	int length;
	printf("Number of values for x: ");
	scanf("%d", &length);
	printf("a b c d: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d values of x: ", length);
	for (i=0; i<length; ++i) {
		scanf("%d", &x);
		if (x > d) fx = a*x*x + b*x + c;
		else if (x == d) fx = 0;
		else fx = -a*x*x + b*x - c;
		printf("f(%d) = %d\n", x, fx);
	}
	return 0;
}

