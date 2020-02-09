#include <cstdio>

int f(int n, int A, int B);

int main()
{
    int n, A, B;
    while (scanf("%d%d%d", &A, &B, &n) == 3 && (A | B | n))
    {
        printf("%d\n", f(n, A, B));
    }
    return 0;
}

int f(int n, int A, int B)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        return (A * f(n - 1, A, B) + B * f(n - 2, A, B)) % 7;
    }
}