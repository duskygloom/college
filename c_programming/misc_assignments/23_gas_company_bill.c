// gas company bill

#include <stdio.h>

#define MAX_CUSTOMERNUMBERLEN 20

int getstring(char *string, int maxlength);

int main()
{
	char customer_number[MAX_CUSTOMERNUMBERLEN];
	double previous_reading, new_reading, gas_used, 
		   total_bill = 0.0;
	int n, i;
	printf("Number of inputs: ");
	scanf("%d", &n);
	getchar();
	for (i=0; i<n; ++i) {
		printf("\nCustomer number: ");
		getstring(customer_number, MAX_CUSTOMERNUMBERLEN);
		printf("Previous meter reading: ");
		scanf("%lf", &previous_reading);
		printf("New meter reading: ");
		scanf("%lf", &new_reading);
		getchar();
		gas_used = new_reading - previous_reading;
		// setting bill
		if (gas_used > 8350) 
			total_bill = 1437.5 + (gas_used - 8350) * 0.08;
		else if (gas_used > 5850)
			total_bill = 712.5 + (gas_used - 5850) * 0.09;
		else if (gas_used > 3350)
			total_bill = 437.5 + (gas_used - 3350) * 0.11;
		else if (gas_used > 350)
			total_bill = 77.5 + (gas_used - 350) * 0.12;
		else if (gas_used > 50)
			total_bill = 40 + (gas_used - 50) * 0.125;
		else if (gas_used > 0)
			total_bill = 40;
		// printing details
		printf("\nCustomer number: %s\n", customer_number);
		printf("Previous reading: %.2lf\n", previous_reading);
		printf("New reading: %.2lf\n", new_reading);
		printf("Gas used: %.2lf\n", gas_used);
		printf("Total bill: %.2lf\n", total_bill);
	}
	return 0;
}

int getstring(char *string, int maxlength)
{
	char ch;
	int length = 0;
	while ((ch=getchar()) != '\n') {
		*string = ch;
		++string;
		++length;
	}
	*string = '\0';
	return length;
}

