#include <stdio.h>

int main(int argc, char **argv)
{
	char ch;
	int is_alpha;
	printf("Character: ");
	ch = getchar();
	is_alpha = (ch>='A' && ch<='Z') || (ch>='a' && ch<='z');
	switch (is_alpha) {
		case 0:
			printf("Not an alphabet.\n");
			break;
		case 1:
			switch (ch) {
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
					printf("Vowel.\n");
					break;
				default:
					printf("Consonant.\n");
					break;
			}
	}
	return 0;
}

