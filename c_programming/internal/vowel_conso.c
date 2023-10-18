#include <stdio.h>
#define MAX_STRING_LEN 50

int main()
{
	int vowel, conso;
	vowel = conso = 0;
	char string[MAX_STRING_LEN];
	printf("String: ");
	scanf("%s", string);
	// counting vowels and consos
	char *cursor = string;
	while (*cursor) {
		// if alphabet
		if ((*cursor >= 'A' && *cursor <='Z') || (*cursor >= 'a' && *cursor <= 'z')) {
			// vowel cases
			switch (*cursor) {
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					++vowel;
					break;
				default:
					++conso;
					break;
			}							// switch closes
		}								// if closes
		++cursor;
	}									// while closes
	printf("Vowels: %d\nConsonants: %d\n", vowel, conso);
	return 0;
}										// main closes

