// https://vjudge.net/contest/396539#problem/C
//类似于n皇后
#include <iostream>
using namespace std;
int n, k;                                        //棋盘长度为n，棋子数目为k
int cnt = 0;                                     //标记每种情况的方案输
void NQueue(int m, int t, int a[][10], int b[]); //在前1~m-1行,已经放置1~t-1个棋子，在第m行放置第t个棋子
int main()
{
    while (cin >> n >> k && (n != -1) && (k != -1))
    {
        int a[10][10];   //存储棋盘
        int b[10] = {0}; //存储每一行棋子的位置，若是没有放置棋子，则为0
        char ch;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> ch;
                if (ch == '#')
                    a[i][j] = true;
                else
                    a[i][j] = false;
            }
        }
        cnt = 0;
        NQueue(2, 1, a, b); //第1行不放棋子
        //第1行放棋子
        for (int i = 1; i <= n; i++)
        {
            if (a[1][i] == 1)
            {
                b[1] = i;
                NQueue(2, 2, a, b);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

void NQueue(int m, int t, int a[][10], int b[])
{
    if (t > k)
        cnt++;
    else if (m > n)
        return;
    else
    {
        //在第m行不放棋子
        NQueue(m + 1, t, a, b);
        //在第m行放棋子，逐列尝试放置棋子
        int i;
        for (i = 1; i <= n; i++)
        {
            if (a[m][i] == true)
            {
                int j;
                for (j = 1; j < m; j++)
                {
                    if (b[j] == i)
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    b[m] = i;
                    NQueue(m + 1, t + 1, a, b);
                }
            }
        }
    }
    return;
}