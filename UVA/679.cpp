#include <cstdio>
#include <cstring>
#include <cstdlib>
const int maxn = 20;
int a[1 << maxn]; //存储每个结点的开关情况，0为关，1为开

int main()
{
    int l;
    while (scanf("%d", &l) == 1 && l != -1)
    {
        int D, I;
        while (l--)
        {
            scanf("%d%d", &D, &I);
            int n = (1 << D) - 1, k = 1;
            memset(a, 0, sizeof(a));
            for (int i = 1; i <= I; i++)
            {
                k = 1;
                while (1)
                {
                    a[k] = !a[k];
                    k = a[k] ? 2 * k : 2 * k + 1;
                    if (k > n)
                        break;
                }
            }
            printf("%d\n", k / 2);
        }
    }
    return 0;
}