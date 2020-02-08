#include <cstdio>
int main()
{
    int N, M;
    scanf("%d", &N);
    while (N--)
    {
        int sum = 0, x;
        scanf("%d", &M);
        while (M--)
        {
            scanf("%d", &x);
            sum += x;
        }
        if (N)
            printf("%d\n\n", sum);
        else
        {
            printf("%d\n", sum);
        }
    }
    return 0;
}