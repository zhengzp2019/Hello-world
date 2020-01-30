#include <stdio.h>
#include <string.h>
int cnt[10];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            int j = i;
            do
            {
                cnt[j % 10]++;
            } while (j /= 10);
        }
        int first = 1;
        for (int i = 0; i <= 9; i++)
        {
            if (first)
            {
                printf("%d", cnt[i]);
                first = !first;
            }
            else
            {
                printf(" %d", cnt[i]);
            }
        }
        printf("\n");
    }
    return 0;
}