// common elements in 2 arrays

#include <stdio.h>

void getarray(int *array, int length);

int main()
{
	int lengthA, lengthB, i, j;
	printf("Length of arrays: ");
	scanf("%d %d", &lengthA, &lengthB);
	int arrayA[lengthA], arrayB[lengthB];
	getarray(arrayA, lengthA);
	getarray(arrayB, lengthB);
	printf("Common elements:");
	for (i=0; i<lengthA; ++i)
		for (j=0; j<lengthB; ++j)
			// comparing each element of A to every elements of B
			if (arrayA[i] == arrayB[j]) {
				printf(" %d", arrayA[i]);
				break;
			}
	putchar('\n');
	return 0;
}

void getarray(int *array, int length)
{
	int i;
	printf("%d elements: ", length);
	for (i=0; i<length; ++i)
		scanf("%d", array+i);
}

