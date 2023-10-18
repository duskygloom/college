// display string in uppercase

#include <stdio.h>

#define MAX_STRLEN 128

int getstring(char *string, int maxlength);
void print_capital(char *string, int length);

int main()
{
	char string[MAX_STRLEN];
	printf("String: ");
	int length = getstring(string, MAX_STRLEN);
	printf("Capitalised string: ");
	print_capital(string, length);
	putchar('\n');
	return 0;
}

int getstring(char *string, int maxlength)
{
	char ch;
	int length = 0;
	while ((ch=getchar()) != '\n' && length < maxlength) {
		*string = ch;
		++string;
		++length;
	}
	*string = '\0';
	return length;
}

void print_capital(char *string, int length)
{
	int i;
	char ch;
	for (i=0; i<length; ++i) {
		ch = *(string+i);
		if (ch>='a' && ch<='z')
			putchar(ch - 32);			// 'a' - 'A' = 32
		else
			putchar(ch);
	}
}

