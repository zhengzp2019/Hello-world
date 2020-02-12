#include <cstdio>
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        int t = 0;
        if (a > b)
        {
            t = a;
            a = b;
            b = t;
        }
        int max = 1;
        for (int i = 2; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0 && i > max)
                max = i;
        }
        printf("%d\n", a * b / max);
    }
    return 0;
}