#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string esp, sap;
    while (cin >> esp >> sap)
    {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (auto &&ch : esp)
        {
            cnt1[ch - 'A']++;
        }
        for (auto &&ch : sap)
        {
            cnt2[ch - 'A']++;
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        if (cnt1 == cnt2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}