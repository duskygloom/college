#include "nrzl.h"
#include <stdio.h>
#include <string.h>
#include "../c_utils/list/list.h"

#define DATAFILE "data.txt"

int main(int argc, char *argv[]) {
    // validating file
    FILE *file = getfile(argc, argv);
    if (!file) {
        puts("Invalid file.");
        return 1;
    }
    // reading hexadecimal
    String *hex = readhex(file);
    fclose(file);
    fputs("Hexadecimal in file: ", stdout);
    puts(hex->content);
    // hexadecimal to binary signal
    String *signal = getsignal(hex->content);
    deletestr(hex);
    fputs("Equivalent signal: ", stdout);
    puts(signal->content);    
    // binary signal to x and y values
    List *xs = createlist(), *ys = createlist();
    storeXY(xs, ys , signal);
    FILE *valfile = fopen(DATAFILE, "w");
    printlist(xs, valfile);
    fputc('\n', valfile);
    printlist(ys, valfile);
    fputc('\n', valfile);
    fclose(valfile);
    fputs("Press Enter to plot graph. ", stdout);
    getchar();
    int status = creategraph(DATAFILE, signal->length);
    deletestr(signal);
    // plot the graph
    deletelist(xs);
    deletelist(ys);
    printf("Exited with status code: %d\n", status);
    return 0;
}
