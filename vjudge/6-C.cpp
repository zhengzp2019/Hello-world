// https://vjudge.net/contest/400708#problem/C
#include <iostream>
#include <vector>
using namespace std;

struct Block
{
    int aa;
    int bb;
    int ab;
    int ba;
    bool isSelect;
};

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n, m;
        cin >> n >> m;
        vector<Block> a;
        while (n--)
        {
            Block b;
            cin >> b.aa >> b.ab >> b.ba >> b.bb;
            if (b.ab == b.ba)
            {
                b.isSelect = true;
                a.push_back(b);
            }
        }
        if (m % 2 != 0 || a.size() == 0) 
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}