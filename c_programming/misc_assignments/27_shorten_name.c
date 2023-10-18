// shorten names with initials

#include <stdio.h>

#define MAX_NAMELEN 128

void get_short_name();

char to_upper(char ch);

int main()
{
	char ch;
	char first_letters[MAX_NAMELEN];
	char last_letters[MAX_NAMELEN];
	int first_index = 0, last_index = 0, spaces = 0;
	printf("Name: ");
	ch = to_upper(getchar());
	first_letters[first_index++] = ch;
	last_letters[last_index++] = ch;
	while ((ch=getchar()) != '\n') {
		switch (ch) {
			case ' ':
				last_index = 0;
				ch = to_upper(getchar());
				first_letters[first_index++] = ch;
				last_letters[last_index++] = ch;
				++spaces;
				break;
			default:
				last_letters[last_index++] = ch;
				break;
		}
	}
	first_letters[first_index] = last_letters[last_index] = '\0';
	printf("Shortened name: ");
	// prints first spaces first letters
	for (first_index=0; first_index<spaces; ++first_index)
		printf("%c.", first_letters[first_index]);
	// prints a space before last name if there are previous names
	if (first_index != 0) putchar(' ');
	printf("%s\n", last_letters);
	return 0;
}

char to_upper(char ch)
{
	if (ch>='a' && ch<='z')
		return ch - 'a' + 'A';
}

