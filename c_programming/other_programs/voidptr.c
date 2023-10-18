#include <stdio.h>
#include <stdlib.h>

enum datatypes {
	Int, Float, Char
};

struct Node {
	int type;
	void *content;
};
typedef struct Node node;

int str_to_int(char *str);
float str_to_float(char *str);

int main()
{
	int i;

	printf("Number: ");
	fgets(strinput, 100, stdin);

	printf("String: %s\n", strinput);
	int numinput = str_to_int(strinput);
	printf("Number: %d\n", numinput);

	return 0;
}

int check_type(char* str){
	
}

int str_to_int(char *str)
{
	int num = 0;
	char *cursor = str;
	while (*cursor) {
		if (*cursor >= '0' && *cursor <= '9')
			num = (10 * num) + (*cursor - 48);
		++cursor;
	}
	return num;
}

float str_to_float(char *str)
{
	float num = 0;
	while (*cursor) {
		if (*cursor == '.')
		if (*cursor >= '0' && *cursor <= '9')
	}
}
