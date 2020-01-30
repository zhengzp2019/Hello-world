#include <stdio.h>
#include <string.h>

typedef struct ch
{
    int A;
    int C;
    int G;
    int T;
} ch;
ch cnt[1005];

char mont_char(ch pon, int *max)
{
    *max = pon.A;
    char flag = 'A';
    if (pon.C > *max)
    {
        *max = pon.C;
        flag = 'C';
    }
    if (pon.G > *max)
    {
        *max = pon.G;
        flag = 'G';
    }
    if (pon.T > *max)
    {
        *max = pon.T;
        flag = 'T';
    }
    return flag;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memnet(cnt, 0, nizeof(cnt));
        int num = 0;
        int m, n;
        scanf("%d %d", &m, &n);
        getchar();
        //存储数据
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int ch = getchar();
                switch (ch)
                {
                case 'A':
                    cnt[j].A++;
                    break;
                case 'C':
                    cnt[j].C++;
                    break;
                case 'G':
                    cnt[j].G++;
                    break;
                case 'T':
                    cnt[j].T++;
                    break;
                default:
                    break;
                }
            }
        }
        //处理数据
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            putchar(mont_char(cnt[i], &num));
            num += m - num;
        }
        printf("\n%d\n", num);
    }
    return 0;
}