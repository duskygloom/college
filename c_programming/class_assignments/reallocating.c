#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr, i, size, increment;
	printf("Array size: ");
	scanf("%d", &size);
	arr = malloc(size * sizeof(int));
	printf("%d elements: ", size);
	for (i=0; i<size; ++i)
		scanf("%d", arr+i);
	printf("Array:");
	for (i=0; i<size; ++i)
		printf(" %d", *(arr+i));
	putchar('\n');

	printf("Increasing array size...\nArray increment size: ");
	scanf("%d", &increment);
	arr = realloc(arr, (size+increment)*sizeof(int));
	printf("Reallocated.\n");
	printf("%d more elements: ", increment);
	for (i=size; i<size+increment; ++i)
		scanf("%d", arr+i);
	printf("Array:");
	for (i=0; i<size+increment; ++i)
		printf(" %d", *(arr+i));
	putchar('\n');
	return 0;
}

