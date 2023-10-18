#include <stdio.h>

#define PIXELCHAR '.'

/*
. . . . . .
 . .     . .
  .   . .   .
   .   . .   .
    . .     . .
	 . . . . . .

. . . . . .
. .     . .
.   . .   .
.   . .   .
. .     . .
. . . . . .
*/

int main()
{
	int side, arraysize, i, j;
	printf("Side: ");
	scanf("%d", &side);
	for (i=0; i<side; ++i) {
		for (j=0; j<i; ++j)
			putchar(' ');					// moving lines toward left
		for (j=0; j<side; ++j) {
			if (j == 0 || j == side-1 || i == 0 || i == side-1 || i == j || j == (side-i-1)) {
				putchar(PIXELCHAR);
				putchar(' ');
			}
			else {
				putchar(' ');
				putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
}

