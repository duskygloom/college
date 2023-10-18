#include <stdio.h>
#include <string.h>

struct Student {
	char name[100];
	int class;
	char section;
};

typedef struct Student Stud;

void set_attributes(Stud *);
void print_student(Stud *);

int main(int argc, char **argv)
{
	Stud student;
	set_attributes(&student);
	print_student(&student);
	return 0;
}

void set_attributes(Stud *student)
{
	strcpy(student->name, "Harsh");
	student->class = 12;
	student->section = 'D';
}

void print_student(Stud *student)
{
	printf("Name: %s\nClass: %d\nSection: %c\n", 
			student->name, 
			student->class, 
			student->section);
}

