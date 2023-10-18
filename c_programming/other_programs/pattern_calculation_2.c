#include <stdio.h>

int main()
{
	int num, i;
	long int sum = 0;
	fputs("Number: ", stdout);
	scanf("%d", &num);
	// for (i=1; i<=num; i+=2)
	//	sum += i;
	// for (i=2; i<=num; i+=2)
	//	sum -= i;
	if (num % 2 == 0)
		sum = -(num / 2);
	else
		sum = (num + 1) / 2;
	printf("Result = %ld\n", sum);
	return 0;
}

