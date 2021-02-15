// https://vjudge.net/contest/397402#problem/B
#include <iostream>
#include <cmath>
using namespace std;

bool eat(int k, long long int n); //共n颗糖，翔翔每次吃k颗，翔翔吃的糖数是否大于1/2n

int main()
{
    long long int n;
    cin >> n;
    int left = 1, right = n;
    int min = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (!eat(mid, n))
            left = mid + 1;
        else
        {
            min = mid;
            right = mid - 1;
        }
    }
    cout << min << endl;
    return 0;
}

bool eat(int k, long long int n)
{
    int i = 0;   //标记吃糖次数
    int num = 0; //记录翔翔最后一次吃的糖数
    int m = n;
    while (n > 0)
    {
        //翔翔吃糖
        if (n > k)
        {
            n = n - k;
            i++;
        }
        else
        {
            num = n;
            n = 0;
        }
        //蕊蕊吃糖
        n = n - (long long int)floor(n * 0.1);
        // cout << n << endl;
    }
    cout << "翔翔每次吃了" << k << "个糖果\n";
    cout << "共吃了" << i + 1 << "次\n";
    cout << "翔翔吃的糖果数：" << i * k + num << endl;
    if (i * k + num > m / 2)
    {
        return true;
    }
    return false;
}