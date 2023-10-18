#include <math.h>
#include <stdio.h>

int main()
{
	int a, b, c, discriminant;
    double root_a, root_b;
	printf("ax2 + bx + c = 0\na b c: ");
	scanf("%d %d %d", &a, &b, &c);
	discriminant = b*b - 4*a*c;
	if (discriminant < 0) {
		printf("No real roots.\n");
	}
	else if (discriminant == 0) {
		root_a = (double)(-b) / (2*a);
		printf("One root: %lf\n", root_a);
	}
	else {
		root_a = ((double)(-b) + sqrt(discriminant)) / (2*a);
		root_b = ((double)(-b) - sqrt(discriminant)) / (2*a);
		printf("Two roots: %lf and %lf\n", root_a, root_b);
	}
	return 0;
}

