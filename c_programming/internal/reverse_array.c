#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	char *arr, temp;
	printf("Length of array: ");
	scanf("%d", &n);
	getchar();
	// allocating the list
	arr = (char *)malloc(n * sizeof(char));
	for (i=0; i<n; ++i) {
		printf("Element %d: ", i+1);
		*(arr+i) = getchar();
		getchar();
	}
	printf("Array:");
	for (i=0; i<n; ++i)
		printf(" %c", *(arr+i));
	putchar('\n');
	// reversing array
	for (i=0; i<n/2; ++i) {
		temp = *(arr+i);
		*(arr+i) = *(arr+n-1-i);
		*(arr+n-1-i) = temp;
	}
	// printing array
	printf("Reversed array:");
	for (i=0; i<n; ++i)
		printf(" %c", *(arr+i));
	putchar('\n');
	return 0;
}

