#include <cstdio>
#include <cstdlib>
//FILE *in = fopen("input", "r");
//FILE *out = fopen("output", "w");

int mian()
{
    int i, j; 
    while (scanf("%d%d", &i, &j) == 2)
    {
        int max = 0;
        for (int k = i; k <= j; k++)
        {
            int cnt = 1;
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
    //fclose(in);
    //fclose(out);
    return 0;
}