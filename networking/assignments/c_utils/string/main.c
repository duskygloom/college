#include <stdio.h>
#include "string.h"

int main() {
    str *a = blankstr();
    str *b = blankstr();
    fputs("String A: ", stdout);
    getstr(a, 20);
    fputs("String B: ", stdout);
    getstr(b, 20);
    if (comparestr(a, b->content)) puts("They are the same.");
    else puts("They are different.");
    return 0;
}
