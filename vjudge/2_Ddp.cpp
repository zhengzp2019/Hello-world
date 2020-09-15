#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 100
using namespace std;
int a[] = {0, 1, 2, 3, 5, 10, 20};
int w[7];
set<int> mp;

int n;

void dfs(int i, int sum)
{
    if (i == 6)
    {
        if (mp.find(sum) == mp.end())
        { //未出现
            n++;
            mp.insert(sum);
        }
        return;
    }

    if (mp.find(sum) == mp.end())
    { //未出现
        n++;
        mp.insert(sum);
    }
    dfs(i + 1, sum);
    dfs(i + 1, sum + a[i + 1] * w[i + 1]);
    return;
}

int main()
{
    for (int j = 0; j < MAXN; j++)
    {
        for (int i = 1; i <= 6; i++)
        {
            cin >> w[i];
        }
    }
    dfs(0, 0);
    cout << "Total=" << n - 1 << endl;
    return 0;
}