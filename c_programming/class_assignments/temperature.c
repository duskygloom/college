#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fahrenheit;
	if (argc == 1)  {
		printf("Temperature in fahrenheit: ");
		scanf("%i", &fahrenheit);
	}
	else fahrenheit = atoi(argv[1]);
	int celsius = (fahrenheit - 32) * (5.0 / 9);
	printf("Temperature in celsius: %i\n", celsius);
	return 0;
}
