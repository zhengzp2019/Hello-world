#include <cstdio>
int main()
{
    int i, j;
    while (scanf("%d%d", &i, &j) == 2)
    {
        int a, b;
        if (i > j)
        {
            a = j;
            b = i;
        }
        else
        {
            a = i;
            b = j;
        }
        int max = 0;
        for (int t = a; t <= b; t++)
        {
            int cnt = 1, k = t;
            while (k != 1)
            {
                if (k % 2)
                {
                    k = k * 3 + 1;
                }
                else
                {
                    k /= 2;
                }
                cnt++;
            }
            if (cnt > max)
            {
                max = cnt;
            }
        }
        printf("%d %d %d\n", i, j, max);
    }
    return 0;
}