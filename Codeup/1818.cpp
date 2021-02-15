// http://codeup.cn/problem.php?id=1818&csrf=6cmWqdxhhjwpIxeeMNVd2STNjHlu5hfs
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
        cout << gcd(a, b) << endl;
    }
    return 0;
}