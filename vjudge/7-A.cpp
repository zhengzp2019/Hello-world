// https://vjudge.net/contest/402838#problem/A
#include <iostream>
using namespace std;

int main()
{
    int n; //记录次数
    // int a = 1;   //记录n-1的正方形边长
    int sum = 1; //记录n次小正方形个数
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        sum += 4 * (i - 1);
        // a = i * 2 - 1;
    }
    cout << sum << endl;
    return 0;
}