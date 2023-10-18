// employee data with structs

#include <stdio.h>

#define MAX_NAMELEN 128
#define CURRENT_YEAR 2023

typedef struct {
	int day;
	int month;
	int year;
} Date;

typedef struct {
	int emp_number;
	char name[MAX_NAMELEN];
	float pay;
	Date join_date;
} Employee;

void increasing_pay(Employee *emp_array, int length);

void print_details_20_years(Employee *emp_array, int length);

int main()
{
	int num_employees, i;
	printf("Number of employees: ");
	scanf("%d", &num_employees);
	Employee employees[num_employees];
	// getting employee data
	for (i=0; i<num_employees; ++i) {
		printf("\nEmployee %d\n", i+1);
		printf("Employee number: ");
		scanf("%d", &(employees[i].emp_number));
		getchar();
		printf("Employee name: ");
		scanf("%[^\n]s", employees[i].name);
		printf("Employee pay: ");
		scanf("%f", &(employees[i].pay));
		printf("Date of joining (dd mm yyyy): ");
		scanf("%d %d %d", &(employees[i].join_date.day),
				&(employees[i].join_date.month), 
				&(employees[i].join_date.year));
	}
	increasing_pay(employees, num_employees);
	print_details_20_years(employees, num_employees);
	return 0;
}

void increasing_pay(Employee *emp_array, int length)
{
	int i;
	for (i=0; i<length; ++i) {
		if (emp_array[i].pay <= 2000)
			emp_array[i].pay *= 1.15;		// 1+15/100 = 1.15
		else if (emp_array[i].pay <= 5000)
			emp_array[i].pay *= 1.1;		// 1+10/100 = 1.10
	}
}

void print_details_20_years(Employee *emp_array, int length)
{
	int i;
	printf("\nEmployees who have completed 20 years of service.\n");
	for (i=0; i<length; ++i) {
		if (CURRENT_YEAR - emp_array[i].join_date.year >= 20) {
			printf("\nEmployee number: %d\n", emp_array[i].emp_number);
			printf("Employee name: %s\n", emp_array[i].name);
			printf("Employee pay: %.2f\n", emp_array[i].pay);
			printf("Date of joining: %d-%d-%d\n", 
					emp_array[i].join_date.day,
					emp_array[i].join_date.month,
					emp_array[i].join_date.year);
		}
	}
}

