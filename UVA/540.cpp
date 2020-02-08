#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int maxn = 1000 + 5;
int main()
{
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;//team[x]表示编号为x的人所在的团队编号
        for (int i = 0; i < t; i++)
        {
            int n, x; //x为队员编号
            scanf("%d", &n);
            while (n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q1, q2[maxn]; //q1为团队整体的队列，q2[t]为团队成员的队列
        char cmd[10];
        while (scanf("%s", cmd) == 1)
        {
            if (cmd[0] == 'S')
                break;
            if (cmd[0] == 'D')
            {
                int t = q1.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q1.pop();
            }
            if (cmd[0] == 'E')
            {
                int x; //队员编号
                scanf("%d", &x);
                int t = team[x]; //团队编号
                if (q2[t].empty())
                    q1.push(t);//团队t入队
                q2[t].push(x);
            }
        }
        putchar('\n');
    }
    return 0;
}