#include "nrzl.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    // validating file
    FILE *file = getfile(argc, argv);
    if (!file) {
        puts("Invalid file.");
        return 1;
    }
    // reading hexadecimal
    str *hex = readhex(file);
    fclose(file);
    fputs("Hexadecimal in file: ", stdout);
    puts(hex->content);
    // hexadecimal to binary signal
    str *signal = getsignal(hex->content);
    deletestr(hex);
    fputs("Equivalent signal: ", stdout);
    puts(signal->content);    
    // binary signal to x and y values
    str *xvalues = blankstr(), *yvalues = blankstr();
    deletestr(signal);
    // plot the graph
    deletestr(xvalues);
    deletestr(yvalues);
    return 0;
}
