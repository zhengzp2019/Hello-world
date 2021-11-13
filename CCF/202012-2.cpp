#include <iostream>
#include <algorithm>
using namespace std;

struct elm
{
    int y;
    int r;
};

const int N = 1e5 + 100;
int perfix[N], suffix[N];
elm a[N];
int m;

bool cmp(elm a, elm b)
{
    return a.y < b.y;
}

int main()
{
    cin.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i].y >> a[i].r;

    sort(a, a + m, cmp);

    // 求第i个元素前面result==0的数目(不包括i)
    for (int i = 1; i < m; i++)
        perfix[i] = perfix[i - 1] + (a[i - 1].r == 0 ? 1 : 0);

    // 求第i个元素后面1的数目(包括i)
    for (int i = m - 1; i >= 0; i--)
        suffix[i] = suffix[i + 1] + (a[i].r == 1 ? 1 : 0);

    pair<int, int> res;
    for (int i = 0; i < m;)
    {
        // cout << a[i].y << ' ' << perfix[i] + suffix[i] << endl;
        if (perfix[i] + suffix[i] > res.first)
        {
            res.first = perfix[i] + suffix[i];
            res.second = a[i].y;
        }
        else if (perfix[i] + suffix[i] == res.first)
            res.second = max(res.second, a[i].y);
        do
            i++;
        while (i < m && a[i].y == a[i - 1].y);
    }
    cout << res.second << endl;
    return 0;
}