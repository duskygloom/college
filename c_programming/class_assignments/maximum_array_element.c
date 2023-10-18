#include <stdio.h>
#include <stdlib.h>

void printarray(int *arr, int len)
{
	int i;
	printf("Array:");
	for (i=0; i<len; ++i)
		printf(" %d", *(arr+i));
	putchar('\n');
}

int maximum_sort(int *arr, int len)
{
	if (len < 2) return *arr;
	if (*arr < *(arr + 1))
		return maximum_sort(arr+1, --len);
	else {
		int temp = *arr;
		*arr = *(arr + 1);
		*(arr + 1) = temp;
		return maximum_sort(arr+1, --len);
	}
}

int main()
{
	int len, *array, i, max;
	printf("Length of array: ");
	scanf("%d",&len);
	array = malloc(len * sizeof(int));
	printf("Enter %d elements: ", len);
	for (i=0; i<len; ++i)
		scanf("%d", array+i);
	printarray(array, len);
	max = maximum_sort(array, len);
	printf("Maximum element: %d\n", max);
	printarray(array, len);
	free(array);
	return 0;
}

