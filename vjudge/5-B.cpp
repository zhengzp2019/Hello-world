// https://vjudge.net/contest/397402#problem/B
#include <iostream>
#include <cmath>
using namespace std;

int n;

bool check(int mid)
{
    int m = n;
    int cnt = 0;
    while (m > 10 && m > mid)
    {
        m -= mid;
        cnt++;
        int tmp = m * 0.1;
        m -= tmp;
    }
    return mid * cnt + m >= 0.5 * n ? true : false;
}

int main()
{
    cin >> n;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
