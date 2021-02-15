// https://vjudge.net/contest/404332#problem/C
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std;
struct node
{
    int x;
    int y;
    int step;
};

int x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
bool visit[9][9]; //标记每一位置是否入队
int main()
{
    string str;
    istringstream ss;
    while (getline(cin, str))
    {
        node Node;
        memset(visit, false, sizeof(visit));
        queue<node> q;
        char x1, x2, y1, y2;
        ss.str(str);
        ss >> y1 >> x1 >> y2 >> x2;
        Node.step = 0;
        Node.x = x1 - '0';
        Node.y = y1 - 'a' + 1;
        q.push(Node);
        while (!q.empty())
        {
            node top = q.front();
            if (top.x == x2 - '0' && top.y == y2 - 'a' + 1)
            {
                printf("To get from %c%c to %c%c takes %d knight moves.\n", y1, x1, y2, x2, top.step);
                break;
            }
            else
            { //访问
                visit[top.x][top.y] = true;
                for (int i = 0; i < 8; i++)
                {
                    Node.x = top.x + x[i];
                    Node.y = top.y + y[i];
                    Node.step = top.step + 1;
                    if (Node.x >= 1 && Node.x <= 8 && Node.y >= 1 && Node.y <= 8 && !visit[Node.x][Node.y])
                        q.push(Node);
                }
            }
            q.pop();
        }
    }
    return 0;
}