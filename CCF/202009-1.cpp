// http://118.190.20.162/view.page?gpid=T113
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    int num;
    long dis;
};

int X, Y, n;
bool cmp(Point a, Point b)
{
    if (a.dis < b.dis)
        return true;
    else if (a.dis == b.dis)
        return a.num < b.num;
    else
        return false;
}

int main()
{
    cin >> n >> X >> Y;
    Point pp[210];
    for (int i = 0; i < n; i++)
    {
        pp[i].num = i + 1;
        cin >> pp[i].x >> pp[i].y;
        pp[i].dis = pow(X - pp[i].x, 2) + pow(Y - pp[i].y, 2);
    }
    sort(pp, pp + n, cmp);
    for (int i = 0; i < 3; i++)
    {
        cout << pp[i].num << endl;
    }
    return 0;
}