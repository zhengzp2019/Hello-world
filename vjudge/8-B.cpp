// https://vjudge.net/contest/404332#problem/B
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
    int loc;  //标记位置
    int step; //标记步数
};
int x[] = {-1, 1, 2};
bool visit[100000 + 100]; //标记结点是否在队列中
int main()
{
    int N, K;
    while (cin >> N >> K)
    {
        queue<node> q;
        memset(visit, false, sizeof(visit));
        node Node;
        Node.loc = N;
        Node.step = 0;
        q.push(Node);
        while (!q.empty())
        {
            node top = q.front();
            if (top.loc == K)
            {
                cout << top.step << endl;
                break;
            }
            else if (top.loc <= 100100 && top.loc >= 0 && visit[top.loc] == false)
            {
                visit[top.loc] = true;
                for (int i = 0; i < 3; i++)
                {
                    if (i != 2)
                        Node.loc = top.loc + x[i];
                    else
                        Node.loc = top.loc * x[i];
                    Node.step = top.step + 1;
                    q.push(Node);
                }
            }
            q.pop();
        }
    }
    return 0;
}