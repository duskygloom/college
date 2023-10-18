#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *max = malloc(sizeof(int));
    printf("A B: ");
    scanf("%d %d", a, b);
    if (*a > *b)
        *max = *a;
    else
        *max = *b;
    printf("Maximum: %d\n", *max);
    return 0;
}

