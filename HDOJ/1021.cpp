#include <cstdio>

int Fibonacci(int n);
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (Fibonacci(n) % 3 == 0)
            printf("yes\n");
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

int Fibonacci(int n)
{
    if (n == 1)
        return 11;
    else if (n == 0)
        return 7;
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}