#ifndef MY_STRING_H
#define MY_STRING_H

#define STRING_DEFAULT_SIZE 8

typedef struct {
	int size, length;
	char *content;
} str;

str *blankstr(void);
str *createstr(const char *content, int length);
void deletestr(str *string);

str *concatchar(str *string, const char ch);
str *concatstr(str *string, const char *content, int length);

/*
	Function comparestr:
		compares str object str1 to char * object str2
		when comparing two str objects, use comparestr(str1, str2->content)
		returns 0 if not equal
		returns 1 if equal
*/
int comparestr(const str *str1, char *str2);

/*
	Function assignstr:
		assigns new content to string
		if content is NULL, does not change the string
			just returns string
		returns the content added into the string
			string->content
*/
char *assignstr(str *string, const char *content, int length);

int getstr(str *string, int length);
void printstr(str *string);

#endif
