// https://vjudge.net/contest/393679#problem/E
// 垃圾炸弹
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    int cnt;
    Point *next;
    Point(int xx = 0, int yy = 0, int ccnt = 0) : x(xx), y(yy), cnt(ccnt)
    {
        next = NULL;
    }
};

int d;                                   //炸弹威力
int n;                                   //有垃圾的位置数目
int traverse(Point *head, int x, int y); //返回链表在位置（x,y)能清楚垃圾的数目

int main()
{
    cin >> d >> n;
    Point *head = new Point;
    // 输入
    for (int i = 1; i <= n; i++)
    {
        int x, y, cnt;
        cin >> x >> y >> cnt;
        Point *p = new Point(x, y, cnt);
        p->next = head->next;
        head->next = p;
    }
    int max = 0; //记录能清楚的垃圾总数
    int num = 1; //记录能清楚垃圾最多的投放点数目
    for (int i = 0; i <= 1024; i++)
        for (int j = 0; j <= 1024; j++)
        {
            int sum = traverse(head->next, i, j);
            if (sum > max)
            {
                max = sum;
                num = 1;
            }
            else if (sum == max)
            {
                num++;
            }
        }
    cout << num << ' ' << max << endl;
    return 0;
}

int traverse(Point *head, int x, int y) //返回能清除的垃圾的总数
{
    int sum = 0;
    if (head == NULL)
        return 0;
    else
    {
        if (abs(head->x - x) <= d && abs(head->y - y) <= d)
            sum += head->cnt;
        sum += traverse(head->next, x, y);
    }
    return sum;
}