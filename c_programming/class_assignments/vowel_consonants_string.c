#include <stdio.h>

int isAlphabet(char ch)
{
    // returns 1 if ch is a character else 0
    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;
    return 0;
}

int main()
{
	char str[] = "This is the C programming language.";
    char *cursor = str;
    int vowels, consonants;
    vowels = consonants = 0;
    while (*cursor) {
        if (isAlphabet(*cursor)) {
            switch (*cursor) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    ++vowels;
                    break;
                default:
                    ++consonants;
                    break;
            }
        }
        ++cursor;
    }
    printf("String: %s\n", str);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
	return 0;
}

