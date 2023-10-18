// diagonal difference

#include <stdio.h>

int main()
{
	int size, difference, temp, i, j;
	printf("Size of the square matrix: ");
	scanf("%d", &size);
	printf("Matrix:\n");
	for (i=0; i<size; ++i) {
		for (j=0; j<size; ++j) {
			scanf("%d", &temp);
			// diagonals are when i == j or i + j = size - 1
			if (i == j)
				difference += temp;
			if (i + j == size - 1)
				difference -= temp;
		}
	}
	if (difference < 0) difference = -difference;
	printf("Diagonal difference = %d\n", difference);
	return 0;
}

