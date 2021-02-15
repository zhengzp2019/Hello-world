#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    { //a<b
        if (a > b)
        {
            int t = b;
            b = a;
            a = t;
        }
        int ans = 0; //标记最大公因数
        for (int i = a; i >= 1; i--)
        {
            if (a % i == 0 && b % i == 0)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}