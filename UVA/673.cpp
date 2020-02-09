#include <cstdio>
#include <cstdlib>
FILE *in = fopen("input", "r");
FILE *out = fopen("output", "w");
int main()
{
    int i, j;
    while (fscanf(in, "%d%d", &i, &j) == 2)
    {
        int max = 0;
        for (int k = i; k <= j; k++)
        {
            int cnt = 1;
            while (k == 1)
            {
                if (k % 2)
                    k /= 2;
                else
                    k = k * 3 + 1;
                cnt++;
            }
            if (cnt > max)
                max = cnt;
        }
        fprintf(out, "%d %d %d\n", i, j, max);
    }
    return 0;
}