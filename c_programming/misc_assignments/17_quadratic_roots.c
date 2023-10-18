// quadratic roots

#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, D;
	double val1, val2;
	printf("a b c: ");
	scanf("%d %d %d", &a, &b, &c);
	D = b * b - 4 * a * c;
	if (D < 0) {
		val1 = (double)(-b) / (2 * a);
		val2 = sqrt((-D)) / (2 * a);
		// placing i and using root (-D)
		printf("Roots = %.2lf+%.2lfi, %.2lf-%.2lfi\n", 
				val1, val2, val1, val2);
	}
	else if (D == 0) {
		val1 = (double)(-b) / (2 * a);
		printf("Root = %.2lf\n", val1);
	}
	else {
		val1 = (double)((-b) + sqrt(D)) / (2 * a);
		val2 = (double)((-b) - sqrt(D)) / (2 * a);
		printf("Roots = %.2lf, %.2lf\n", val1, val2);
	}
	return 0;
}

