#include <stdio.h>

int main()
{
    int n, r, i;
    float c = 1.0f;
    printf("n r: ");
    scanf("%d %d", &n, &r);
    for (i=0; i<r; ++i) {
        c *= (float)n - i;
        c /= (float)r - i;
    }
    printf("%dC%d = %.2f\n", n, r, c);
    return 0;
}

