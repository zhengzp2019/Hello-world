/**
 * wsy又去找女生玩纸牌游戏啦，规则如下，在纸牌上写下一个正整数a，
 * 要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，
 * （其中 1 < a1 <= a2 <= a3 <= ... <= an），
 * wsy要写出这样的分解的种数有多少（注意a = a也是一种分解） 
 * wsy又想不过来啦，你们帮帮他吗QAQ?
 */
#include <iostream>
#include <cmath>
using namespace std;

int q(int n, int m);  //求最大因子ｎ１小于m的n的因式分解的数目
int f(int n, int m);  //求距离m最近的最大的能被n整除的因子(包括m)
bool isPrimer(int n); //判断n是否为素数
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        cout << q(a, f(a, a)) << endl;
    }
    return 0;
}

int q(int n, int m)
{
    if (n <= 1 || m <= 1)
        return 0;
    else if (isPrimer(n))
    { //n>=1&&m>=2
        return 1;
    }
    else if (m > n)
    {
        return q(n, n);
    }
    else if (n == m)
        return q(n, f(n, m - 1)) + 1;
    else if (n % m == 0)
    { //2<m<n
        return q(n / m, f(n / m, m)) + q(n, f(n, m - 1));
    }
    else
    { //n%m!=0
        return q(n, f(n, m));
    }
}

int f(int n, int m)
{
    if (n % m == 0)
        return m;
    else
    {
        for (int i = m - 1; i >= 1; i--)
        {
            if (n % i == 0)
                return i;
        }
    }
    return 1;
}

bool isPrimer(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    if (i > sqrt(n))
    {
        return true;
    }
    return true;
}