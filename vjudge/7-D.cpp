// https://vjudge.net/contest/402838#problem/D
#include <iostream>
using namespace std;

int result[210][10] = {0};
int sum = 0;
int a[10] = {1};
// 前num-1个人已经分配好，开始分配第num个人和之后的人
int distribute(int n, int k, int num)
{
    if (k < 0 || n < 0)
        return 0;
    if (k == 1 || n == 1)
        return result[n][k] = 1;
    else
    {
        for (int i = a[num - 1]; i <= n - k + 1; i++)
        {
            a[num] = i;
            if (result[n - i][k - 1] == 0)
                result[n - i][k - 1] = distribute(n - i, k - 1, num + 1);
            result[n][k] += result[n - i][k - 1];
        }
    }
    return result[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << distribute(n, k, 1) << endl;
    return 0;
}