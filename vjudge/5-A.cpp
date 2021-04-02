// https://vjudge.net/contest/397402#problem/A?

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
const double N = 1e4 + 20;
int n, k, T;
vector<int> cake_r(N);

//每块蛋糕体积为mid满足题意
bool check(double mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (int)cake_r[i] * cake_r[i] * pi / mid;
    return cnt >= k + 1 ? true : false;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cake_r[i]);
            if (cake_r[i] > max)
                max = cake_r[i];
        }
        double l = 0, r = pi * max * max;
        while ((r - l) > 1e-6)
        {
            double mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%.4lf\n", l);
        cake_r.clear();
    }
    return 0;
}