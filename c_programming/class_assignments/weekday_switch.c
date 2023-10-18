#include <stdio.h>

int main(int argc, char **argv)
{
	int weekday_num;
	printf("Day number: ");
	scanf("%d", &weekday_num);
	switch (weekday_num) {
		case (1):
			printf("Monday\n");
			break;
		case (2):
			printf("Tuesday\n");
			break;
		case (3):
			printf("Wednesday\n");
			break;
		case (4):
			printf("Thursday\n");
			break;
		case (5):
			printf("Friday\n");
			break;
		case (6):
			printf("Saturday\n");
			break;
		case (7):
			printf("Sunday\n");
			break;
		default:
			printf("Day must be between 1 and 7.\n");
			break;
	}
	return 0;
}

