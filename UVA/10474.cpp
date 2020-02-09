#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int a[MAXN];

int main()
{
    int N, Q;
    int kase = 0;
    while (scanf("%d %d", &N, &Q) == 2 && N | Q)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("CASE# %d:\n", ++kase);
        sort(a, a + N);
        int x;
        while (Q--)
        {
            scanf("%d", &x);
            int p = find(a, a + N, x) - a;
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