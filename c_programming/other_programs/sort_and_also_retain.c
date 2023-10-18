#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	int real;		// real position
} Element;

void insert_sorted(int *array, int len, int value);

int main()
{
	int n;
	printf("Number of elements: ");
	scanf("%d", &n);
	int arr[n];
	while ()
	return 0;
}

void insert_sorted(int *array, int len, int value)
{
	int i = 0, temp;
	while (value < array[i++]);
	while (i < len) {
		temp = array[i];
		array[i] = value;
		value = temp;
	}
}