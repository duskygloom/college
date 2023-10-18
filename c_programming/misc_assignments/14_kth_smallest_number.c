// printing kth smallest element

#include <stdio.h>

int main()
{
	int length, i, j, k, temp;
	printf("Length of array: ");
	scanf("%d", &length);
	int array[length];
	printf("%d elements: ", length);
	// inserting elements in ascending order
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
	printf("k: ");
	scanf("%d", &k);
	printf("kth smallest element: %d\n", array[k-1]);
	return 0;
}

