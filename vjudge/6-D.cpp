// https://vjudge.net/contest/400708#problem/D
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        m = n;
        string str;
        vector<int> a(30, 0);
        while (n--)
        {
            cin >> str;
            for (auto &&ch : str)
            {
                a[ch - 'a']++;
            }
        }
        int i;
        for (i = 0; i < 26; i++)
        {
            if (a[i] == 0)
                continue;
            else
            {
                if (a[i] % m != 0)
                    break;
            }
        }
        if (i >= 26)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}