// https://vjudge.net/contest/397402#problem/B
#include <iostream>
#include <cmath>
using namespace std;

bool eat(int k, long long int n); //共n颗糖，翔翔每次吃k颗，翔翔吃的糖数是否大于1/2n

int main()
{
    // long long int n;
    // cin >> n;
    // int left = 1, right = n;
    // int min = n;
    eat(3, 68);
    // while (left <= right)
    // {
    //     int mid = left + (right - left) / 2;
    //     if (!eat(mid, n))
    //         left = mid + 1;
    //     else
    //     {
    //         min = mid;
    //         right = mid - 1;
    //     }
    // }
    // cout << min << endl;
    return 0;
}

bool eat(int k, long long int n)
{
    /* cout << "k == " << k << endl;
    double up = log(1 - (double)n / (9 * k + n));
    double down = log(0.9);
    // cout << "分子 == " << up << "\n分母 == " << down << endl;
    double cnt = up / down; //翔翔每次吃个糖果，吃完所有糖果所需要的次数
    cout << "cnt == " << cnt << endl;
    double an = (9 * k + n) * (1 - pow(0.9, (int)cnt)); //前n次吃掉的糖果数目
    cout << "an == " << an << endl;
    cout << "翔翔吃的糖数：" << cnt * k + n - an << endl;
    if (cnt * k + n - an > n / 2)
    {
        return true;
    } */
    // double up = log(1 - (double)n / (9 * k + n));
    // double down = log(0.9);
    double an = 0;
    int i;
    for (i = 1; an <= n; i++)
    {
        an = (9 * k + n) * (1 - pow(0.9, i));
        if (n - floor(an) > 10)
            cout << "第" << i << "次之后吃的糖果数:" << floor(an) << endl;
        else
            break;
    }
    return false;
}