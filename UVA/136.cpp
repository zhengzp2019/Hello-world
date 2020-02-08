#include <set>
#include <queue>
#include <iostream>
using namespace std;
typedef long long int LL;
const int a[] = {2, 3, 5};
int main()
{
    set<LL> s;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    pq.push(1);
    s.insert(1);
    for (size_t i = 1;; i++)
    {
        LL x = pq.top();
        pq.pop();
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is " << x << '.' << endl;
            break;
        }
        for (size_t i = 0; i < 3; i++)
        {
            LL x2 = x * a[i];
            if (s.find(x2) == s.end())
            {
                pq.push(x2);
                s.insert(x2);
            }
        }
    }
    return 0;
}