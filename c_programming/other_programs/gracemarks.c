#include <stdio.h>

void printarray(int *array, int length);

int main()
{
	int marks[] = {12, 13, 14, 23, 1, 3, 2, 45, 1, 3};
	printarray(marks, 10);
	for (int i=0; i<10; ++i)
		*(marks+i) = *(marks+i) + 1;
	printarray(marks, 10);
	return 0;
}

void printarray(int *array, int length)
{
	fputs("Array:", stdout);
	for (int i=0; i<length; ++i)
		printf(" %d", array[i]);
	putchar('\n');
}

