#include <stdio.h>
#define MAXPAPERLEN 100

int main()
{
	int students, papers, i, j;
	printf("Number of papers: ");
	scanf("%d", &papers);
	printf("\nNumber of students: ");
	scanf("%d", &students);
	putchar('\n');

	// scanning the data
	float paper_marks[papers][students];
	for (i=0; i<students; ++i) {
		for (j=0; j<papers; ++j) {
			printf("Paper %d: ", j+1);
			scanf("%f", &paper_marks[i][j]);
		}
		putchar('\n');
	}

	// printing average in all papers
	double average;
	for (i=0; i<students; ++i) {
		average = 0.0;
		for (j=0; j<papers; ++j)
			average += paper_marks[i][j];
		average = average / papers;
		printf("Average in Paper %d: %.2lf\n", i+1, average);
	}

	return 0;
}

