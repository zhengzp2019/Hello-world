#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 10000 + 100;
int a[MAXN];
int main()
{
    int N, Q;
    int kase = 0;
    while (scanf("%d %d", &N, &Q) == 2 && N | Q)
    {
        memset(a, -1, sizeof(a));
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
        }
        fprintf(out, "CASE# %d:\n", ++kase);
        sort(a, a + N);
        int x;
        while (Q--)
        {
            scanf("%d", &x);
            int p = find(a, a + N, x) - a; //在数组（a,a+N）中查找元素x
            if (a[p] == x)
            {
                printf("%d found at %d\n", x, p + 1);
            }
            else
            {
                printf("%d not found\n", x);
            }
        }
    }
    return 0;
}