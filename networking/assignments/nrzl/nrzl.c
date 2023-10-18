#include "nrzl.h"
#include <stdio.h>

FILE *getfile(int argc, char **argv) {
    if (argc <= 1) {
        puts("Provide a file as command-line argument.");
        return NULL;
    }
    FILE *file = fopen(argv[1], "r");
    return file;
}

str *readhex(FILE *file) {    
    if (!file) {
        puts("Invalid file.");
        return NULL;
    }
    int ch;
    str *hex = blankstr();
    for (ch = getc(file); ishex(ch); ch = getc(file))
        concatchar(hex, ch);
    return hex;
}

str *getsignal(const char *hex) {
    str *signal = blankstr();
    str *bin = blankstr();
    // will automatically stop when reads '\0' at the end due to hextobin
    for (int i = 0; assignstr(bin, hextobin(hex[i]), 4); ++i)
        concatstr(signal, bin->content, 4);
    deletestr(bin);
    return signal;
}
