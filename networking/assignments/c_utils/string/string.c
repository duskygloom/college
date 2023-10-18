#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

str *blankstr(void) {
	str *string = malloc(sizeof(str));
	string->content = malloc(STRING_DEFAULT_SIZE * sizeof(char));
	string->size = STRING_DEFAULT_SIZE;
	string->length = 0;
	string->content[0] = '\0';
	return string;
}

str *createstr(const char *content, int length) {
	int nblocks = length / STRING_DEFAULT_SIZE + 1;
	str *string = malloc(sizeof(str));
	string->content = malloc(nblocks * STRING_DEFAULT_SIZE * sizeof(char));
	string->size = nblocks * STRING_DEFAULT_SIZE;
	string->length = length;
	string->content = memcpy(string->content, content, length);
	return string;
}

void deletestr(str *string) {
	free(string->content);
	free(string);
}

str *concatchar(str *string, const char ch) {
    if (string->size - string->length <= 1) {
        string->size += STRING_DEFAULT_SIZE;
        string->content = realloc(string->content, string->size);
    }
    char *stringptr = string->content;
    for (; *stringptr; ++stringptr);
    *stringptr = ch;
    ++stringptr;
    *stringptr = '\0';
    ++string->length;
    return string;
}

/*
	Function concatstr:
		value of length is very crucial
		because it directly adds length to the existing length
		so use carefully
		returns the same string after concatenation
*/
str *concatstr(str *string, const char *content, int length) {
	int needed = string->length + length;
	if (needed >= string->size) {
		int nblocks = needed / STRING_DEFAULT_SIZE + 1;
		string->size = nblocks * STRING_DEFAULT_SIZE;
		string->content = realloc(string->content, string->size);
	}
	char *stringptr = string->content;
	for (; *stringptr; ++stringptr);
	memcpy(stringptr, content, length);
	*(stringptr + length) = '\0';
	string->length += length;
	return string;
}

int comparestr(const str *str1, char *str2) {
	char *strptr1 = str1->content;
	char *strptr2 = str2;
	// running the loop till the strings are the same
	for (; *strptr1 && *strptr2 && *strptr1 == *strptr2; ++strptr1, ++strptr2);
	// returns if the current strptrs are both '\0'
	return !(*strptr1 || *strptr2);
}

char *assignstr(str *string, const char *content, int length)
{
	if (!content) return NULL;

	if (length >= string->size) {
		int nblocks = length / STRING_DEFAULT_SIZE + 1;
		string->size = nblocks * STRING_DEFAULT_SIZE;
		string->content = realloc(string->content, string->size);
	}

	memcpy(string->content, content, length);
	*(string->content + length) = '\0';
	string->length = length;
	return string->content;
}

int getstr(str *string, int length)
{
    int counter = 0, ch;
	for (ch = getchar(); counter < length && ch != '\n'; ch = getchar(), ++counter)
		concatchar(string, ch);
	return counter;
}

void printstr(str *string) {
	char *stringptr = string->content;
	for (; *stringptr; ++stringptr) putchar(*stringptr);
}
