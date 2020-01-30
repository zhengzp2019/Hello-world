#include <string.h>
#include <stdio.h>
char s[1000000], t[1000000];
const char Yes[] = "Yes", No[] = "No";
int main()
{
    while (scanf("%s %s", s, t) != EOF)
    {
        int last = 0, flag = 0;
        int S = strlen(s), T = strlen(t);
        int first = 1;
        for (int i = 0; i < S; i++)
        {
            int j = 0;
            if (first)
            {
                j = 0;
                first = !first;
            }
            else
            {
                j = last + 1;
            }
            for (; j < T; j++)
            {
                if (t[j] == s[i])
                {
                    flag++;
                    last = j;
                    break;
                }
            }
        }
        if (t[last] == s[S - 1] && flag == S)
        {
            puts(Yes);
        }
        else
        {
            puts(No);
        }
    }
    return 0;
}