#include <iostream>
#include <cmath>
using namespace std;
bool is_primer(int n);
int main()
{
    int S;
    int max = 0;
    cin >> S;
    for (int i = S / 2; i >= 2; i--)
    {
        if (is_primer(i) && is_primer(S - i))
        {
            if (i * (S - i) > max)
            {
                max = i * (S - i);
            }
        }
    }
    cout << max;
    return 0;
}

bool is_primer(int n)
{
    int i, m;
    for (i = 2; i <= (m = sqrt(n)); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    if (i > m)
    {
        return true;
    }
    return false;
}