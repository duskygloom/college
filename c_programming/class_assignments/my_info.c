#include <stdio.h>
#include <string.h>

struct Info {
	char name[100];
	char department[100];
	char course[50];
	char contact_no[20];
	char email_id[50];
	char application_no[20];
};

void print_details(struct Info info);

int main()
{
	struct Info my_info;
	strcpy(my_info.name, "Harsh Sarkar");
	strcpy(my_info.department, "Computer and System Sciences");
	strcpy(my_info.course, "B.Sc Hons");
	strcpy(my_info.contact_no, "+911234567890");
	strcpy(my_info.email_id, "xxxxxx@xxxxxx.com");
	strcpy(my_info.application_no, "xxxxxxxxx");

	print_details(my_info);
	return 0;
}

void print_details(struct Info info)
{
	printf("*** Information ***\n");
	printf("Name: %s\n", info.name);
	printf("Department: %s\n", info.department);
	printf("Course: %s\n", info.course);
	printf("Contact number: %s\n", info.contact_no);
	printf("Email ID: %s\n", info.email_id);
	printf("Application number: %s\n", info.application_no);
}

