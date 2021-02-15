// https://vjudge.net/contest/396539#problem/B

/**
 * 类似于斐波那契数列，递推
 */

/* #include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        long long int ai_2 = 1,
                      ai_1 = 2,
                      ai;
        int n, m;
        cin >> m >> n;
        if (n == m + 2)
            cout << ai_1 << endl;
        else if (n == m + 1)
            cout << ai_2 << endl;
        else
        {
            for (int i = 3; i <= n - m; i++)
            {
                ai = ai_1 + ai_2;
                ai_2 = ai_1;
                ai_1 = ai;
            }
            cout << ai << endl;
        }
    }
    return 0;
}
 */

//类似于斐波那契数列，递归
#include <iostream>
using namespace std;
const int MANX = 50 + 5;                      //存储从m到n的路劲数目
long long int rote(int n, long long int a[]); //走n步的路径数
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int m, n;
        long long int a[MANX] = {0};
        cin >> m >> n;
        cout << rote(n - m, a) << endl;
    }
    return 0;
}

long long int rote(int n, long long int a[])
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return a[1] = 1;
    else if (n == 2)
        return a[2] = 2;
    else
    {
        if (a[n] != 0)
            return a[n];
        else
            return a[n] = rote(n - 1, a) + rote(n - 2, a);
    }
}