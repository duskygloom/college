#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, result;
	printf("A B: ");
	scanf("%d %d", &a, &b);
	result = a > b;
	switch (result) {
		case 0:
			printf("%d is greater.\n", b);
			break;
		case 1:
			printf("%d is greater.\n", a);
			break;
	}
	return 0;
}

