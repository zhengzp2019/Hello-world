// http://118.190.20.162/view.page?gpid=T105
#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
    char ch;
};

int main()
{
    int a, b, c; //标记直线方程的三个参数
    int n, m;
    cin >> n >> m;
    vector<Point> pset(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pset[i].x >> pset[i].y >> pset[i].ch;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        bool first; //记录第一个元素的在直线的位置（上或下）
        char ch;    //记录第一个元素的类别
        ch = pset[0].ch;
        first = a + b * pset[0].x + c * pset[0].y > 0 ? true : false;
        int j;
        for (j = 0; j < n; j++)
        {
            // 先判断A
            if (pset[j].ch == ch)
            {
                if (first == (a + b * pset[j].x + c * pset[j].y > 0 ? true : false))
                    continue;
                else
                    break;
            }
            // 判断B
            else
            {
                if (first != (a + b * pset[j].x + c * pset[j].y > 0 ? true : false))
                    continue;
                else
                    break;
            }
        }
        if (j >= n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}