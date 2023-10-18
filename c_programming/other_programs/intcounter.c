#include <stdio.h>

int main()
{
    int number, numcopy, i;
    int counter[10] = {0};
    fputs("Number: ", stdout);
    scanf("%d", &number);
    numcopy = number;

    while (numcopy > 0) {
        ++counter[numcopy % 10];
        numcopy = numcopy / 10;
    }
     
    for (i=0; i<10; ++i)
        printf("%d: %d, ", i, counter[i]);
    printf("\b\b  \n");
    
    return 0;
}
