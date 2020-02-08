#include<cstdio>
int main()
{
    int N;
    while (scanf("%d",&N)==1&&N)
    {
        int sum = 0, x;
        while(N--)
        {
            scanf("%d", &x);
            sum += x;
        }
        printf("%d\n", sum);
    }
    return 0;
}