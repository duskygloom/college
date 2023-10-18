// sort n elements

#include <stdio.h>
#include <stdlib.h>

int *sort_elements(int length);

int main()
{
	int n, i;
	printf("n: ");
	scanf("%d", &n);
	int *sorted = sort_elements(n);
	printf("Sorted elements:");
	for (i=0; i<n; ++i) printf(" %d", *(sorted+i));
	putchar('\n');
	return 0;
}

int *sort_elements(int length)
{
	// insertion sort
	int i, j, k, temp;
	int *array = malloc(length * sizeof(int));
	printf("%d elements: ", length);
	for (i=0; i<length; ++i) {
		// getting elements length times
		scanf("%d", &temp);
		for (j=0; j<i; ++j) {
			if (temp < array[j]) {
				// shifting elements
				for (k=i-1; k>=j; --k)
					array[k+1] = array[k];
				break;
			}
		}
		// setting jth element
		array[j] = temp;
	}
	return array;
}
