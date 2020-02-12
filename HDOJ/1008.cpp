#include <cstdio>

int main()
{
    int N;
    while (scanf("%d", &N) == 1 && N)
    {
        int now_floor, pre_floor = 0, sum = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &now_floor);
            if (now_floor > pre_floor)
                sum += (now_floor - pre_floor) * 6;
            else
                sum += (pre_floor - now_floor) * 4;
            pre_floor = now_floor;
        }
        printf("%d\n", sum + 5 * N);
    }
    return 0;
}