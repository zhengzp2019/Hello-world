#include<cstdio>
int main()
{
    int T;
    scanf("%d", &T);
    int n;
    while(T--)
    {
        scanf("%d", &n);
        int t = n;
        for (int i = 1; i < n; i++)
        {
            t = (t % 10) * n;
        }
        printf("%d\n", t%10);
    }
    return 0;
}