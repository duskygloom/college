#include "nrzl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PYTHON "C:/Users/sarka/Home/Programs/college/networking/Scripts/python.exe"
#define PLOTTER "C:/Users/sarka/Home/Programs/college/networking/assignments/plotter/main.py"
#define NOISES "C:/Users/sarka/Home/Programs/college/networking/assignments/nrzl/noise.dat"

FILE *getfile(int argc, char **argv) {
    if (argc <= 1) {
        puts("Provide a file as command-line argument.");
        return NULL;
    }
    FILE *file = fopen(argv[1], "r");
    return file;
}

String *readhex(FILE *file) {
    if (!file) {
        puts("Invalid file.");
        return NULL;
    }
    int ch;
    String *hex = blankstr();
    for (ch = getc(file); ishex(ch); ch = getc(file))
        concatchar(hex, ch);
    return hex;
}

String *getsignal(const char *hex) {
    String *signal = blankstr();
    String *bin = blankstr();
    // will automatically stop when reads '\0' at the end due to hextobin
    for (int i = 0; assignstr(bin, hextobin(hex[i]), 4); ++i)
        concatstr(signal, bin->content, 4);
    deletestr(bin);
    return signal;
}

void storeXY(List *xlist, List *ylist, const String *signals) {
    FILE *noisefile = fopen(NOISES, "r");
    float noise, signal;
    for (int i = 0; i < signals->length; ++i) {
        for (int j = 0; j < NUM_SAMPLES_PER_BIT; ++j) {
            append(xlist, i + (float)j/NUM_SAMPLES_PER_BIT);
            fscanf(noisefile, "%f", &noise);
            signal = signals->content[i]-'0';
            signal += noise;
            signal = 2*signal - 1;
            append(ylist, signal);
        }
    }
    fclose(noisefile);
}

int creategraph(char *datafile, int nsignal) {
    String *command = createstr(PYTHON, strlen(PYTHON));
    concatchar(command, ' ');
    concatstr(command, PLOTTER, strlen(PLOTTER));
    concatstr(command, " --data ", 8);
    concatstr(command, datafile, strlen(datafile));
    concatstr(command, " --nsignal ", 11);
    String *n = itos(nsignal);
    concatstr(command, n->content, n->length);
    concatstr(command, " --title NRZ-L", 14);
    concatstr(command, " --xlabel \"Time (ms)\"", 21);
    concatstr(command, " --ylabel Signal", 16);
    deletestr(n);
    printstr(command, stdout);
    putchar('\n');
    int status = system(command->content);
    deletestr(command);
    return status;
}
