#ifndef NRZL_H
#define NRZL_H

#include "../c_utils/string/string.h"
#include <stdio.h>
#include <ctype.h>

/*
    Function
        getfile:
            returns the file specified by the user
            returns NULL if the file is not present or argument has not been provided
            user must close the file after use
    Arguments
        argc:
            number of arguments provided to main
        argv:
            array of arguments (char *)
*/
FILE *getfile(int argc, char **argv);

static inline int ishexdigit(int ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

static inline int ishex(char hex) {
    switch (hex) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
            return 1;
        default:
            return 0;
    }
}

static inline char *hextobin(char hex) {
    switch (hex) {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'a':
        case 'A':
            return "1010";
        case 'b':
        case 'B':
            return "1011";
        case 'c':
        case 'C':
            return "1100";
        case 'd':
        case 'D':
            return "1101";
        case 'e':
        case 'E':
            return "1110";
        case 'f':
        case 'F':
            return "1111";
        default:
            return NULL;
    }
}

/*
    Function
        readhex:
            returns the hexadecimal as char * in the file
            stops reading at the character which does not contain a hex digit
    Arguments
        file:
            the file stream in which the hexadecimal is stored
*/
str *readhex(FILE *file);

str *getsignal(const char *hex);

#endif
