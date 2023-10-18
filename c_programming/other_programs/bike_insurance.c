#include <stdio.h>

int get_bike_age();
float power(float base, int pow);
float get_insurance_cost(int age);
void print_insurance_cost(float cost);

int main()
{
	int bike_age = get_bike_age();
	float insurance_cost = get_insurance_cost(bike_age);
	print_insurance_cost(insurance_cost);
	return 0;
}

int get_bike_age()
{
	int age;
	printf("Age of bike in months: ");
	scanf("%d", &age);
	return age;
}

float power(float base, int pow)
{
	float value = 1;
	for (; pow > 0; --pow)
		value *= base;
	return value;
}

float get_insurance_cost(int age)
{
	float cost = 0;
	if (age < 12) return cost;
	age -= 12;
	// A = P (1 + r/100)^n
	// (1 + r/100) = 1.05
	// n = age / 6
	cost = 500 * power(1.05, age/6);
	return cost;
}

void print_insurance_cost(float cost)
{
	printf("Insurance cost is Rs %.2f\n", cost);
}

