// https://vjudge.net/contest/396539#problem/A
//类似于走楼梯，或斐波那契数列
#include <iostream>
using namespace std;

int sum(int n); //求n颗糖可以有多少种吃法
int main()
{
    int n;
    while (cin >> n)
        cout << sum(n) << endl;
    return 0;
}

int sum(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else
    {
        return sum(n - 1) + sum(n - 2);
    }
    return 0;
}