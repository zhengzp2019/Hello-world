#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXN 100

int main()
{
    int a, b, c, d, e, f;
    srand(time(NULL));
    for(int i = 0; i < MAXN;)
    {
        a = rand() % 1000;
        b = rand() % 500;
        c = rand() % 300;
        d = rand() % 200;
        e = rand() % 100;
        f = rand() % 50;
        if (a + b * 2 + c * 3 + d * 5 + e * 10 + f * 20 > 1000)
            continue;
        else
        {
            ++i;
            printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
        }
    }
    return 0;
}