#include <stdio.h>

int main()
{
	int xa, xb, ya, yb, i, j, k;

    // first matrix
	printf("Number of rows: ");
	scanf("%d", &ya);
	printf("Number of columns: ");
	scanf("%d", &xa);
	int matrix_a[ya][xa];
	printf("Matrix A:\n");
	for (i=0; i<ya; ++i) {
		for (j=0; j<xa; ++j)
			scanf("%d", &matrix_a[i][j]);
	}
	putchar('\n');

    // second matrix
    printf("Number of rows: ");
	scanf("%d", &yb);
	printf("Number of columns: ");
	scanf("%d", &xb);
    if (xa != yb) {
        printf("The matrices can't be multiplied.\n");
        return 0;
    }
	int matrix_b[yb][xb];
	
	printf("Matrix B:\n");
	for (i=0; i<yb; ++i) {
		for (j=0; j<xb; ++j)
			scanf("%3d", &matrix_b[i][j]);
	}
	putchar('\n');

	int matrix_product[ya][xb];

	// setting all elements to 0
	for (i=0; i<ya; ++i) {
		for (j=0; j<xb; ++j)
			matrix_product[i][j] = 0;
	}

	// multiplying
	for (i=0; i<ya; ++i) {
		for (j=0; j<xb; ++j) {
			for (k=0; k<xa; ++k) {
				// printf("%d += %d * %d\n", matrix_product[i][j], matrix_a[i][k], matrix_b[k][j]);
				matrix_product[i][j] += (matrix_a[i][k] * matrix_b[k][j]);
			}
		}
	}

	printf("Product:\n");

	for (i=0; i<ya; ++i) {
		for (j=0; j<xb; ++j)
			printf("%3d ", matrix_product[i][j]);
		putchar('\n');
	}
	return 0;
}
