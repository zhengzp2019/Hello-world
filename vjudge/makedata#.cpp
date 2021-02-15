#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXN 10

int main()
{
    int a, b;
    srand(time(NULL));
    printf("%d\n", MAXN);
    for (int i = 0; i < MAXN; i++)
    {
        a = rand() % 49 + 1;
        b = rand() % 49 + 1;
        if (a > b)
        {
            int t = a;
            a = b;
            b = t;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}