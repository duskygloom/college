// arithmetic operations using operators

#include <stdio.h>

int main()
{
	int num1, num2;
	char op;
	printf("Numbers: ");
	scanf("%d %d", &num1, &num2);
	getchar();
	printf("Operator: ");
	switch (op = getchar()) {
		case '+':
			printf("%d + %d = %d\n", num1, num2, num1+num2);
			break;
		case '-':
			printf("%d - %d = %d\n", num1, num2, num1-num2);
			break;
		case '*':
			printf("%d * %d = %d\n", num1, num2, num1*num2);
			break;
		case '/':
			printf("%d / %d = %d\n", num1, num2, num1/num2);
			break;
		case '%':
			printf("%d %% %d = %d\n", num1, num2, num1%num2);
			break;
		default:
			printf("Unknown operator: %c\n", op);
			break;
	}
	return 0;
}

