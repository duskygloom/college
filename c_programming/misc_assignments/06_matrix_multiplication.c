// multiplication of 2 matrices

#include <stdio.h>
#include <stdlib.h>

int *get_elemref(int *matrix, int row, int col, int cols);
void get_matrix(int *matrix, int rows, int cols);
void print_matrix(int *matrix, int rows, int cols);

int main()
{
	int i, j, k;
	int rows1, cols1, rows2, cols2;
	printf("Dimensions of matrix 1: ");
	scanf("%d %d", &rows1, &cols1);
	printf("Dimensions of matrix 2: ");
	scanf("%d %d", &rows2, &cols2);
	if (cols1 != rows2) {
		printf("> Multiplication not possible.\n");
		return 0;
	}
	int matrix1[rows1*cols1], matrix2[rows2*cols2];
	printf("Matrix 1:\n");
	get_matrix(matrix1, rows1, cols1);
	printf("Matrix 2:\n");
	get_matrix(matrix2, rows2, cols2);
	int *matrix3 = calloc(rows1*cols2, sizeof(int));
	for (i=0; i<rows1; ++i)
		for (j=0; j<cols2; ++j)
			for (k=0; k<rows2; ++k)
				*get_elemref(matrix3, i, j, cols2) += 
					*get_elemref(matrix1, i, k, cols1) * 
					*get_elemref(matrix2, k, j, cols2);
	printf("Product matrix:\n");
	print_matrix(matrix3, rows1, cols2);
	return 0;
}

int *get_elemref(int *matrix, int row, int col, int cols)
{
	// M[r][c] = M[C*r + c]
	int *element = matrix + (row * cols + col);
	return element;
}

void get_matrix(int *matrix, int rows, int cols)
{
	// matrix to be input in grid form
	int i, j;
	for (i=0; i<rows; ++i)
		for (j=0; j<cols; ++j)
			scanf("%d", get_elemref(matrix, i, j, cols));
}

void print_matrix(int *matrix, int rows, int cols)
{
	int i, j;
	for (i=0; i<rows; ++i) {
		for (j=0; j<cols; ++j)
			printf("%d ", *(matrix + (cols * i + j)));
		putchar('\n');
	}
}
