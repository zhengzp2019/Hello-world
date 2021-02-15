// http://118.190.20.162/view.page?gpid=T112
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    Point human[25][1100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> human[i][j].x >> human[i][j].y;
        }
    }
    int pass = 0, remian = 0;
    int mid; //中间变量，记录居民连续在高位地区逗留的时间
    int cnt; //记录居民连续在高危地区逗留的时间
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        mid = 0;
        bool flag = false; //标记是否经过高位地区
        for (int j = 0; j < t; j++)
        {
            Point p = human[i][j];
            if (p.x <= xr && p.x >= xl && p.y <= yu && p.y >= yd)
            {
                flag = true;
                mid++;
            }
            else
            {
                if (mid > cnt)
                    cnt = mid;
                mid = 0;
            }
        }
        if (flag)
            pass++;
        if (cnt >= k || mid >= k)
            remian++;
    }
    cout << pass << '\n'
         << remian << endl;
    return 0;
}