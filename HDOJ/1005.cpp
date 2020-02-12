//预处理
#include <cstdio>
int a[55];

int main()
{
    int n, A, B;
    while (scanf("%d%d%d", &A, &B, &n) == 3 && (A | B | n))
    {
        for (int i = 1; i <= 49; i++)
        {
            if (i == 1 || i == 2)
                a[i] = 1;
            else
            {
                a[i] = (A * a[i - 1] + B * a[i - 2]) % 7;
            }
        }
        printf("%d\n", a[(n - 1) % 49 + 1]);
    }
    return 0;
}