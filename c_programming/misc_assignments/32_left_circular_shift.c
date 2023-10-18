// left circular shift

#include <stdio.h>

#define ARRAY_LENGTH 5
#define ARRAY_SHIFT_VALUE 2
#define MATRIX_ROWS 3
#define MATRIX_COLS 5

void left_circular_shift(int *array, int length, int position);

int main()
{
	int i, j;
	int array[ARRAY_LENGTH];
	printf("%d elements: ", ARRAY_LENGTH);
	for (i=0; i<ARRAY_LENGTH; ++i) scanf("%d", array+i);
	left_circular_shift(array, ARRAY_LENGTH, ARRAY_SHIFT_VALUE);
	printf("Array after shifting:");
	for (i=0; i<ARRAY_LENGTH; ++i) printf(" %d", array[i]);
	putchar('\n');
	// getting matrix
	int matrix[MATRIX_ROWS * MATRIX_COLS];
	printf("\n%dx%d matrix:\n", MATRIX_ROWS, MATRIX_COLS);
	for (i=0; i<MATRIX_ROWS; ++i) {
		for (j=0; j<MATRIX_COLS; ++j) {
			scanf("%d", &matrix[i * MATRIX_COLS + j]);
		}
	}
	// shifting and printing
	// if n row shift, each row is shifted by ARRAY_SHIFT_VALUE
	for (i=0; i<MATRIX_ROWS; ++i) {
		left_circular_shift(matrix+(i*MATRIX_COLS), MATRIX_COLS,
				ARRAY_SHIFT_VALUE);
	}
	// column shift
	// total elements = rows * cols
	// if n column shift, element shift = cols * n
	/*
	left_circular_shift(matrix, MATRIX_ROWS * MATRIX_COLS, 
			ARRAY_SHIFT_VALUE * MATRIX_COLS);
	*/
	printf("Matrix after shifiting:\n");
	for (i=0; i<MATRIX_ROWS; ++i) {
		for (j=0; j<MATRIX_COLS; ++j) {
			printf("%d ", matrix[i * MATRIX_COLS + j]);
		}
		putchar('\n');
	}
	return 0;
}

void left_circular_shift(int *array, int length, int position)
{
	int i, extras[position];
	// storing the first position elements
	for (i=0; i<position; ++i)
		extras[i] = array[i];
	// shifting the next elements
	for (; i<length; ++i)
		array[i-position] = array[i];
	// placing the stores elements at the end
	for (i=0; i<position; ++i)
		array[length-position+i] = extras[i];
}

