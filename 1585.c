#include <stdio.h>
#include <string.h>

char s[85];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int n = strlen(s);
        int count = 0, num = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'O')
            {
                count++;
                num += count;
            }
            else
                count = 0;
        }
        printf("%d\n", num);
    }
    return 0;
}