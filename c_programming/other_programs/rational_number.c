#include <stdio.h>
#include <string.h>

typedef struct
{
	int numerator;
	int denominator;
} Rational;

Rational reduced_rational(Rational r);
float get_floating_value(Rational r);
void get_string_value(Rational r, char *fractional_string);

int main()
{
	Rational a;
	char fractional_string[20];
	printf("Numerator: ");
	scanf("%d", &a.numerator);
	printf("Denominator: ");
	scanf("%d", &a.denominator);
	printf("Value: %f\n", get_floating_value(a));
	get_string_value(a, fractional_string);
	printf("Value: %s\n", fractional_string);
	printf("Value: %f\n", get_floating_value(reduced_rational(a)));
	get_string_value(reduced_rational(a), fractional_string);
	printf("Value: %s\n", fractional_string);
	return 0;
}

Rational reduced_rational(Rational r)
{
	// euclid's algorithm
	// finding HCF and then dividing n and d with it
	int n, d, hcf;
	Rational reduced_r;
	n = r.numerator;
	d = r.denominator;
	while (d != 0) {
		hcf = d;
		d = n % d;
		n = hcf;
	}
	reduced_r.numerator = r.numerator / hcf;
	reduced_r.denominator = r.denominator / hcf;
	return reduced_r;
}

float get_floating_value(Rational r)
{
	return (float)r.numerator / (float)r.denominator;
}

void get_string_value(Rational r, char *fractional_string)
{
	sprintf(fractional_string, "%d/%d", r.numerator, r.denominator);
}

