#include <cstdio>
#include <stack>
#define MAXN 100
using namespace std;
int N, target[MAXN];

int main()
{
    while (scanf("%d", &N) == 1 && N)
    {
        while (scanf("%d", &target[1]) == 1 && target[1])
        {
            stack<int> s;
            int A = 1, B = 1; //入栈前车厢编号为A，入栈后车厢编号为target[B]
            int ok = 1;
            for (int i = 2; i <= N; i++)
            {
                scanf("%d", &target[i]);
            }
            while (B <= N)
            {
                if (A == target[B])
                {
                    A++;
                    B++;
                }
                else
                {
                    if (!s.empty() && s.top() == target[B])
                    {
                        s.pop();
                        B++;
                    }
                    else
                    {
                        if (A <= N)
                        {
                            s.push(A++);
                        }
                        else
                        {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            printf("%s", ok ? "Yes" : "No");
        }
        putchar('\n');
    }
    return 0;
}