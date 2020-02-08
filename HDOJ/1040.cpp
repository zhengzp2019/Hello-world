#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        vector<int> a;
        int M, x;
        cin >> M;
        while (M--)
        {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        bool first = true;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (first)
            {
                cout << a[i];
                first = !first;
            }
            else
            {
                cout << " " << a[i];
            }
        }
        cout << endl;
    }
    return 0;
}