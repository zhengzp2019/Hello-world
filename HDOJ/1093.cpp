#include <cstdio>
int main()
{
    int T;
    int N;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        int sum = 0, x;
        while (N--)
        {
            scanf("%d", &x);
            sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;
}