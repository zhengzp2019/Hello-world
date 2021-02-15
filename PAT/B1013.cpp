// https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n;
    bool isPrime[10100];
    fill(isPrime, isPrime + 10100, true);
    cin >> m >> n;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
    }
    int cnt = 0; //标记每行元素数目
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            if (cnt == 9)
                cout << i;
            else
                cout << i << ' ';
            ++cnt;
        }
        if (cnt % 10 == 0)
        {
            cout << '\n';
            cnt = 0;
        }
    }
    return 0;
}