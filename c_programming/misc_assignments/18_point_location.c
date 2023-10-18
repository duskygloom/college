// point location

#include <stdio.h>

int main()
{
	int x, y;
	printf("x y: ");
	scanf("%d %d", &x, &y);
	// printing axis
	if (x == 0 && y == 0)
		printf("(%d, %d) lies in the origin.\n", x, y);
	else if (y == 0)
		printf("(%d, %d) lies in the X-axis.\n", x, y);
	else if (x == 0)
		printf("(%d, %d) lies in the Y-axis.\n", x, y);
	// printing quadrant
	if (x > 0 && y > 0)
		printf("(%d, %d) lies in quadrant I.\n", x, y);
	else if (x < 0 && y > 0)
		printf("(%d, %d) lies in quadrant II.\n", x, y);
	else if (x < 0 && y < 0)
		printf("(%d, %d) lies in quadrant III.\n", x, y);
	else if (x > 0 && y < 0)
		printf("(%d, %d) lies in quadrant IV.\n", x, y);
}

