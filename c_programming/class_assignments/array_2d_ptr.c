#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arrayindex;
    int rows, cols, i, j;
    fputs("Rows: ", stdout);
    scanf("%d", &rows);
    arrayindex = malloc(5 * sizeof(int *));
    fputs("Columns: ", stdout);
    scanf("%d", &cols);
    putchar('\n');
    // filling array
    for (i=0; i<rows; ++i) {
        int *row = malloc(cols * sizeof(int));
        for (j=0; j<cols; ++j) {
            printf("Element (%d,%d): ", i, j);
            scanf("%d", row+j);
        }
        putchar('\n');
        *(arrayindex + i) = row;
    }
    // reading array
    for (i=0; i<rows; ++i) {
        for (j=0; j<cols; ++j) {
            printf("%2d ", *(*(arrayindex + i) + j));
        }
        putchar('\n');
    }
    // freeing array
    for (j=0; j<rows; ++j)
        free(*(arrayindex + j));
    free(arrayindex);
    return 0;
}
