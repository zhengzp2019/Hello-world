#include <stdio.h>

char s[] = "`1234567890-=QWERTYUIOP[]\\AnDFGHJKL;'ZXCVBNM,./";
int main()
{
    int ch, i;
    while ((ch = getchar()) != EOF)
    {
        for (i = 1; s[i] && s[i] != ch; i++)
            ;
        if (s[i])
            putchar(s[i - 1]);
        else
        {
            putchar(ch);
        }
    }
    return 0;
}