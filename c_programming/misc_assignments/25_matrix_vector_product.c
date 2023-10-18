// matrix vector product

#include <stdio.h>
#include <stdlib.h>

int *get_matrix_and_multiply(int *vector, int length);

int main()
{
	int length, i;
	printf("Dimension: ");
	scanf("%d", &length);
	// getting vector
	int vector[length];
	printf("Vector: ");
	for (i=0; i<length; ++i) scanf("%d", vector+i);
	// getting result
	int *result = get_matrix_and_multiply(vector, length);
	printf("Result:");
	for (i=0; i<length; ++i) printf(" %d", result[i]);
	putchar('\n');
	return 0;
}

int *get_matrix_and_multiply(int *vector, int length)
{
	int i, j, temp;
	int *result = calloc(length, sizeof(vector));
	// vector can be considered a column matrix of 1 
	// column and length rows
	printf("Matrix:\n");
	for (i=0; i<length; ++i) {
		for (j=0; j<length; ++j) {
			scanf("%d", &temp);
			*(result+i) += temp * *(vector+j);
		}
	}
	return result;
}

