#include "customstring.h"

int main()
{
	char str[100];
	int len = getstring(str, 100);
	printf("String: %s\nLength: %d\n", str, len);
	return 0;
}

