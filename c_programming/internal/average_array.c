#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, *arr;
	printf("Length of array: ");
	scanf("%d", &n);
	// taking array and total
	arr = (int *)malloc(n * sizeof(int));
	long total = 0;
	for (i=0; i<n; ++i) {
		printf("Element %d: ", i+1);
		scanf("%d", arr+i);
		total += *(arr + i);
	}
	// printing average
	double average = (double)total / (double)n;
	printf("Average: %lf\n", average);
	return 0;
}

