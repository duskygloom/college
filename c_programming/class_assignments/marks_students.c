#include <stdio.h>

int main()
{
	int n, i;
	double average = 0.0;
	printf("Number of students: ");
	scanf("%d", &n);
	putchar('\n');
	float marks[n];
	for (i=0; i<n; ++i) {
		printf("Marks: ");
		scanf("%f", &marks[i]);
		average += marks[i];
	}
	average = average / n;
	printf("\nMarks: ");
	for (i=0; i<n; ++i) printf("%.1f ", marks[i]);
	putchar('\n');
	putchar('\n');
	printf("Average: %.2lf\n", average);
	return 0;
}

