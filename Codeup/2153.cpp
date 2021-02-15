// http://codeup.cn/problem.php?id=2135
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a / gcd(a, b) * b /* lcm */ << endl;
    }
    return 0;
}