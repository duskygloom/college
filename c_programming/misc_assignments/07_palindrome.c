// check if string is palindrome

#include <stdio.h>

#define MAX_STRLEN 128

int getstring(char *string, int maxlength);

int main()
{
	char string[MAX_STRLEN];
	int palindrome = 1, i;
	printf("String: ");
	int length = getstring(string, MAX_STRLEN);
	for (i=0; i<length/2; ++i)
		// checking first half of the string to last half
		// in reverse order
		if (string[i] != string[length-i-1]) {
			palindrome = 0;
			break;
		}
	if (palindrome)
		printf("%s is palindrome.\n", string);
	else
		printf("%s is not palindrome.\n", string);
	return 0;
}

int getstring(char *string, int maxlength)
{
	int length = 0;
	char ch;
	while ((ch=getchar()) != '\n' && length<maxlength) {
		*string = ch;
		++string;
		++length;
	}
	*string = '\0';
	return length;
}

