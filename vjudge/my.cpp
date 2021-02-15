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