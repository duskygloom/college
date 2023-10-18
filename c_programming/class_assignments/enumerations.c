#include <stdio.h>

enum { FALSE, TRUE };

int main()
{
	int i = 1;
	int j = TRUE;
	if ((i == j) == TRUE)
		printf("1 == TRUE\n");
	else
		printf("1 != TRUE\n");
	return 0;
}

