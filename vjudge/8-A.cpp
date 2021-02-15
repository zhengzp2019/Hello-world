// https://vjudge.net/contest/404332#problem？
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M;
void bfs(int i, int j, vector<vector<char>> &a);
int main()
{
    cin >> N >> M;
    vector<vector<char>> a(N + 5); //a记录农场状况
    for (int i = 0; i < N; i++)
        a[i].resize(M + 5);
    //读入字符
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch;
        }
    }
    int cnt = 0; //记录连通图个数
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == 'W')
            {
                ++cnt;
                bfs(i, j, a);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

//处理所有与(i,j)联通的积水
void bfs(int i, int j, vector<vector<char>> &a)
{
    if (a[i][j] == '.')
        return;
    else
    {
        a[i][j] = '.';
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                int xx = i + dx, yy = j + dy;
                if (xx < 0 || xx >= N || yy < 0 || yy > M)
                    continue;
                else
                    bfs(xx, yy, a);
            }
        }
    }
}