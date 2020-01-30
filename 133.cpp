#include <cstdio>
#include <cstring>
#define MAXN 25
int n, A, B, a[MAXN];
//初始位置p,方向d,-1 为顺时针方向，1 为逆时针方向，t为步长
int go(int p, int d, int t);
int main()
{
    while (scanf("%d%d%d", &n, &A, &B) == 3 && n)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        int left = n, pa = 0, pb = n + 1;
        while (left)
        {
            pa = go(pa, 1, A);
            pb = go(pb, -1, B);
            printf("%3d", a[pa]);
            a[pa] = ' ';
            left--;
            if (pa != pb)
            {
                printf("%3d", a[pb]);
                a[pb] = ' ';
                left--;
            }
            if (left)
            {
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}
int go(int p, int d, int t)
{
    while (t--)
    {
        while (1)
        {
            p = (p + d + n - 1) % n + 1;
            if (a[p] != ' ')
            {
                break;
            }
        }
    }
    return p;
}