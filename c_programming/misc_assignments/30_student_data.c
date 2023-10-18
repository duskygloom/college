// student data struct

#include <stdio.h>

#define MAX_NAMELEN 128
#define MAX_DEPTLEN 128
#define MAX_COURSELEN 128

typedef struct {
	int roll;
	char name[MAX_NAMELEN];
	char department[MAX_DEPTLEN];
	char course[MAX_COURSELEN];
	int join_year;
} Student;

void print_year_students(Student *student_data, int length, int year);

void print_roll_data(Student *student_data, int length, int roll);

int main()
{
	int num_students, i;
	printf("Number of students: ");
	scanf("%d", &num_students);
	Student students[num_students];
	// getting student data
	for (i=0; i<num_students; ++i) {
		printf("\nStudent %d\n", i+1);
		printf("Roll number: ");
		scanf("%d", &(students[i].roll));
		getchar();
		printf("Name: ");
		// %[^\n]s scans until it scans \n
		scanf("%[^\n]s", students[i].name);
		getchar();
		printf("Department: ");
		scanf("%[^\n]s", students[i].department);
		getchar();
		printf("Course: ");
		scanf("%[^\n]s", students[i].course);
		printf("Year of joining: ");
		scanf("%d", &(students[i].join_year));
		getchar();
	}
	// printing students enrolled in year
	int year;
	printf("\nYear of joining: ");
	scanf("%d", &year);
	print_year_students(students, num_students, year);
	// printing data with roll number
	int roll;
	printf("\nRoll number: ");
	scanf("%d", &roll);
	print_roll_data(students, num_students, roll);
	return 0;
}

void print_year_students(Student *student_data, int length, int year)
{
	int i;
	printf("Students who joined in %d:\n", year);
	for (i=0; i<length; ++i) {
		if (student_data[i].join_year == year)
			printf("%s\n", student_data[i].name);
	}
}

void print_roll_data(Student *student_data, int length, int roll)
{
	int i;
	printf("Details about roll number %d:\n", roll);
	for (i=0; i<length; ++i) {
		if (student_data[i].roll == roll) {
			printf("Name: %s\n", student_data[i].name);
			printf("Department: %s\n", student_data[i].department);
			printf("Course: %s\n", student_data[i].course);
			printf("Year of joining: %d\n", 
					student_data[i].join_year);
			break;
		}
	}
}

