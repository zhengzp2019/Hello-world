#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> v0, v1;

int main()
{
    while (cin >> N && N)
    {
        v0.clear();
        for (int i = 1; i <= N; i++)
        {
            v0.push_back(i);
        }

        int m;
        while (cin >> m && m)
        {
            stack<int> s1, s2;
            for (int i = 1; i < N; i++)
            {
                s1.push(m);
                cin >> m;
            }
            s1.push(m);
            int first = s1.top();
            s1.pop();
            int second;
            bool flag = 1;
            while (!s1.empty())
            {
                second = s1.top();
                if (first > second)
                {
                    s2.push(first);
                    first = second;
                    s1.pop();
                    flag = 1;
                }
                else
                {
                    stack<int> s3;
                    while (!s1.empty() && (s1.top() > first))
                    {
                        s3.push(first);
                        first = s1.top();
                        s1.pop();
                    }
                    s3.push(first);
                    while (!s3.empty())
                    {
                        s2.push(s3.top());
                        s3.pop();
                    }
                    flag = 0;
                }
            }
            if (flag)
                s2.push(first);
            v1.clear();
            for (int i = 0; i < N; i++)
            {
                v1.push_back(s2.top());
                s2.pop();
            }
            if (v1 == v0)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        cout << endl;
    }
    return 0;
}