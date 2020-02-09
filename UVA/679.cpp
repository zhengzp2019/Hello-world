#include <cstdio>
#include <cstring>
#include <cstdlib>
const int maxn = 20;
int a[1 << maxn]; //存储每个结点的开关情况，0为关，1为开
FILE *in = fopen("input", "r");
FILE *out = fopen("output", "w");

int main()
{
    int D, I;
    while (fscanf(in, "%d%d", &D, &I) == 2)
    {
        int n = 1 << D, k = 1;
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
        fprintf(out, "%d\n", k / 2);
    }
    fclose(in);
    fclose(out);
    return 0;
}