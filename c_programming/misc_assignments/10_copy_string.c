// copy one string to another

#include <stdio.h>

#define MAX_STRLEN 128

int getstring(char *string, int maxlength);

int main()
{
	int i;
	char string[MAX_STRLEN], string_copy[MAX_STRLEN];
	printf("String: ");
	int length = getstring(string, MAX_STRLEN);
	for (i=0; i<length; ++i)
		string_copy[i] = string[i];
	string_copy[i] = '\0';
	printf("Input string: %s\nCopied string: %s\n",
			string, string_copy);
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

