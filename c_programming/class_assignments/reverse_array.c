#include <stdio.h>

void print_array(int array[], int length);
void reverse_array(int array[], int length, int reversed[]);

int main()
{
    int array[] = {12, 11, 3, 1};
    print_array(array, 4);
    int reversed[4];
    reverse_array(array, 4, reversed);
    print_array(reversed, 4);
    return 0;
}

void print_array(int array[], int length)
{
    putchar('[');
    for (; length>0; --length) {
        printf("%d, ", *array);
        ++array;
    }
    puts("\b\b] ");
}

void reverse_array(int array[], int length, int reversed[])
{
    for (--length; length>=0; --length) {
        *(reversed + length) = *array;
        ++array;
    }
}

