// check if 3 points are collinear

#include <stdio.h>

int main()
{
	int x1, y1, x2, y2, x3, y3;
	printf("x1 y1: ");
	scanf("%d %d", &x1, &y1);
	printf("x2 y2: ");
	scanf("%d %d", &x2, &y2);
	printf("x3 y3: ");
	scanf("%d %d", &x3, &y3);
	// finding 2 * area of triangle
	// if collinear, area = 0, 2*area = 0
	int twice_area = x1 * (y2 - y3) + x2 * (y3 - y1) 
		+ x3 * (y1 - y2);
	if (twice_area == 0)
		printf("Points are collinear.\n");
	else
		printf("Points are not collinear.\n");
	return 0;
}

