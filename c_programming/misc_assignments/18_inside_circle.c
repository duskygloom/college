// check if point is within circle

#include <stdio.h>

#define RADIUS 1

int main()
{
	float x, y;
	printf("x y: ");
	scanf("%f %f", &x, &y);
	float radius_squared = x * x + y * y;
	// for RADIUS = 1, RADIUS = RADIUS^2
	if (radius_squared < RADIUS)
		printf("(%.2f, %.2f) lies within the circle.\n", x, y);
	else if (radius_squared == RADIUS)
		printf("(%.2f, %.2f) lies on the circle.\n", x, y);
	else printf("(%.2f, %.2f) lies outside the circle.\n", x, y);
	return 0;
}

