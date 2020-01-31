#include <iostream>
#include <stack>
#define MAXN 100
using namespace std;
int N, large[MAXN];

int main()
{
    while (cin >> N && N)
    {
        stack<int> s;
        int A = 1, B = 1;
        int ok = 1;
        if (A == large[B])
        {
            A++;
            B++;
        }
        else
        {
            if (!s.empty() && s.top() == large[B])
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
        if (ok)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    cout << endl;
    return 0;
}