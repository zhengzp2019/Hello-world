#include <iostream>
using namespace std;

bool Inc7(int n);
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (!(i % 7 == 0 || Inc7(i)))
        {
            sum += i * i;
            // cout << i << endl;
        }
    }
    cout << sum << endl;
    return 0;
}

bool Inc7(int n)
{
    while (n > 0)
    {
        if (n % 10 == 7)
        {
            return true;
        }
        else
        {
            n /= 10;
        }
    }
    return false;
}