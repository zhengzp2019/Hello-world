#include <stdio.h>
#include <string.h>
#define MAXN 100
int win, left, chance, lose;
char s[MAXN];
void guess(char ch);

int main()
{
    int n;
    char str[MAXN];
    while (scanf("%d",&n)&&n != -1)
    {
        memset(s, 0, sizeof(s));
        memset(str, 0, sizeof(0));
        scanf("%s", s);
        //getchar();
        scanf("%s", str);
        win = lose = 0;
        chance = 7;
        left = strlen(s);
        int ch = strlen(str);
        for (int i = 0; i < ch;i++)
        {
            guess(str[i]);
            if (win || lose)
            {
                break;
            }
        }
        printf("Round %d\n", n);
        if (win)
        {
            printf("You win.\n");
        }
        else
        {
            if (lose)
            {
                printf("You lose.\n");
            }
            else
            {
                printf("You chickened out.\n");
            }
        }
    }
    return 0;
}

void guess(char ch)
{
    int flag = 1, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (ch == s[i])
        {
            --left;
            flag = 0;
            s[i] = ' ';
        }
    }
    if (flag)
    {
        --chance;
    }
    if (!chance)
    {
        lose = 1;
    }
    if (!left)
    {
        win = 1;
    }
}