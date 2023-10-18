#include <stdio.h>

int main()
{
	int x, y, i, j;
	printf("Number of rows: ");
	scanf("%d", &y);
	printf("Number of columns: ");
	scanf("%d", &x);
	int matrix_a[y][x];
	int matrix_b[y][x];
	int matrix_sum[y][x];
	putchar('\n');
	
	printf("Matrix A:\n");
	for (i=0; i<y; ++i) {
		for (j=0; j<x; ++j)
			scanf("%d", &matrix_a[i][j]);
	}

	printf("Matrix B:\n");
	for (i=0; i<y; ++i) {
		for (j=0; j<x; ++j)
			scanf("%d", &matrix_b[i][j]);
	}

	// adding
	for (i=0; i<y; ++i) {
		for (j=0; j<x; ++j)
			matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
	}

	printf("\nSum:\n");

	for (i=0; i<y; ++i) {
		for (j=0; j<x; ++j)
			printf("%d ", matrix_sum[i][j]);
		putchar('\n');
	}
	return 0;
}
