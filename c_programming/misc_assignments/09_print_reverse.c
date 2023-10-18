// print string in reverse order

#include <stdio.h>

#define MAX_STRLEN 128

int getstring(char *string, int maxlength);

int main()
{
	int i;
	char string[MAX_STRLEN];
	printf("String: ");
	int length = getstring(string, MAX_STRLEN);
	// generating reverse index
	printf("Reverse string: ");
	for (i=length-1; i>=0; --i)
		putchar(*(string+i));
	putchar('\n');
	return 0;
}

int getstring(char *string, int maxlength)
{
	int length = 0;
	char ch;
	while ((ch=getchar()) != '\n' && length < maxlength) {
		*string = ch;
		++string;
		++length;
	}
	*string = '\0';
	return length;
}

