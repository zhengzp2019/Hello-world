#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a < 2 || a % 2 != 0)
        {
            cout << 0 << " " << 0 << endl;
        }
        else
        {
            cout << a / 4 + a % 4 / 2 << " " << a / 2 << endl;
        }
    }
    return 0;
}