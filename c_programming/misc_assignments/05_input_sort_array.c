// sort array in descending order

#include <stdio.h>

#define LENGTH_OF_ARRAY 10

int main()
{
	int i, j, k, temp;
	int array[LENGTH_OF_ARRAY];
	printf("%d elements: ", LENGTH_OF_ARRAY);
	for (i=0; i<LENGTH_OF_ARRAY; ++i) {
		scanf("%d", &temp);
		for (j=0; j<i; ++j) {
			if (temp > array[j]) {
				// copying elements to their next memory location
				for (k=i-1; k>=j; --k)
					array[k+1] = array[k];
				break;
			}
		}
		// placing the number at the proper place
		array[j] = temp;
	}
	printf("Array:");
	for (i=0; i<LENGTH_OF_ARRAY; ++i)
		printf(" %d", array[i]);
	putchar('\n');
	return 0;
}

