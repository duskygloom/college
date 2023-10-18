#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nrzl.h"

#define MAX_HEXLEN 64

int check_file(const char *filename) {
    FILE *hexfile = fopen(filename, "r");
    if (hexfile) {
        fclose(hexfile);
        return 1;
    }
    fclose(hexfile);
    return 0;
}

void get_signals(char *signals, char *hex, int hexlen) {
    char *binary = "";
    for (int i = 0; i < hexlen; ++i) {
        switch (hex[i]) {
            case ('0'):
                binary = "0000";
                break;
            case ('1'):
                binary = "0001";
                break;
            case ('2'):
                binary = "0010";
                break;
            case ('3'):
                binary = "0011";
                break;
            case ('4'):
                binary = "0100";
                break;
            case ('5'):
                binary = "0101";
                break;
            case ('6'):
                binary = "0110";
                break;
            case ('7'):
                binary = "0111";
                break;
            case ('8'):
                binary = "1000";
                break;
            case ('9'):
                binary = "1001";
                break;
            case ('a'):
            case ('A'):
                binary = "1010";
                break;
            case ('b'):
            case ('B'):
                binary = "1011";
                break;
            case ('c'):
            case ('C'):
                binary = "1100";
                break;
            case ('d'):
            case ('D'):
                binary = "1101";
                break;
            case ('e'):
            case ('E'):
                binary = "1110";
                break;
            case ('f'):
            case ('F'):
                binary = "1111";
                break;
            default:
                printf("Encountered invalid hexadecimal character: %c\n", hex[i]);
                return;
        }
        for (int j = 0; j < 4; ++j)
            signals[4*i+j] = binary[j];
    }
}

int get_hex_length(const char *filename) {
    // returns the length of the hex in the file
    FILE *hexfile = fopen(filename, "r");
    int length = 0;
    for (char hex = fgetc(hexfile); (hex >= '0' && hex <= '9') || (hex >= 'a' && hex <= 'f') || (hex >= 'A' && hex <= 'F'); hex = fgetc(hexfile))
        ++length;
    fclose(hexfile);
    return length;
}

void get_hex_value(char *hex_string, int hexlen, const char *filename) {
    FILE *hexfile = fopen(filename, "r");
    for (int i = 0; i < hexlen; ++i)
        hex_string[i] = fgetc(hexfile);
    fclose(hexfile);
}

void create_nrzl_graph(char *signals, int signal_length) {
    char *plot_function = "plotter.py";
    char *graph_file = "graph.svg";
    char x_values = calloc(2, signal_length*sizeof(char));
    char *y_values = calloc(3, signal_length*sizeof(char));
    for (int i = 0; i < signal_length; ++i) {
        strcat_char(x_values, signals[i]);
        strcat_char(x_values, signals[i]);
        char buffer[10];
        itoa(i, buffer, 10);
        strcat(y_values, buffer);
        itoa(i+1, buffer, 10);
        strcat(y_values, buffer);
    }
    char *plot_command = calloc((22 + 5*signal_length), sizeof(char));
    strcat(plot_command, plot_function);
    strcat(plot_command, " ");
    strcat(plot_command, graph_file);
    strcat(plot_command, " ");
    strcat(plot_command, x_values);
    strcat(plot_command, " ");
    strcat(plot_command, y_values);
    printf("Command: %s\n", plot_command);
    system(plot_command);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("No file provided as command line argument.\n");
        return 1;
    }
    char *filename = argv[1];
    if (!check_file(filename)) {
        printf("Invalid filename: %s\n", filename);
        return 1;
    }
    int length_hex = get_hex_length(filename);
    printf("Length of hex: %d\n", length_hex);
    char *hexadecimal = malloc(length_hex);
    get_hex_value(hexadecimal, length_hex, filename);
    printf("Hexadecimal: ");
    for (int i = 0; i < length_hex; ++i)
        putchar(hexadecimal[i]);
    char *signals = malloc(4*length_hex*sizeof(char));
    get_signals(signals, hexadecimal, length_hex);
    putchar('\n');
    printf("Signals: ");
    for (int i = 0; i < 4*length_hex; ++i)
        putchar(signals[i]);
    putchar('\n');
    create_nrzl_graph(signals, 4*length_hex);
    free(signals);
    free(hexadecimal);
    return 0;
}
