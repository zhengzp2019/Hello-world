// https://vjudge.net/contest/402838#problem/C
#include <iostream>
using namespace std;

// 返回大的那个数的值
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int N;
        int a[105][105] = {0};
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
                cin >> a[i][j];
        }
        for (int i = N - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                a[i][j] = a[i][j] + max(a[i + 1][j], a[i + 1][j + 1]);
            }
        }
        cout << a[0][0] << endl;
    }
    return 0;
}
