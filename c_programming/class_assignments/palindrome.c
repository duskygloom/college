#include <stdio.h>

int stringlen(char *str);
int isPalindrome(char *str);

int main()
{
    char str[100];
    fputs("String: ", stdout);
    scanf("%s", str);;
    if (isPalindrome(str))
        printf("%s is palindrome.\n", str);
    else
        printf("%s is not palindrome.\n", str);
    return 0;
}

int stringlen(char *str)
{
    int length = 0;
    while (*str) {
        ++length;
        ++str;
    }
    return length;
}

int isPalindrome(char *str)
{
    // returns 1 if palindrome else 0
    int length = stringlen(str);
    int middle = length / 2;
    for (--middle; middle>=0; --middle) {
        // printf("comparing %c and %c.\n", *(str+middle), *(str+(length-1-middle)));
        if (*(str+middle) != *(str+(length-1-middle)))
            return 0;
    }
    return 1;
}

