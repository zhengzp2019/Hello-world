#include <iostream>
#include <cstring>
#define MAXN 1000
using namespace std;
bool Drop[MAXN];

int main()
{
    int T = 0, D = 0, E = 0;
    int n, m;
    int cnt_have, lost;
    memset(Drop, false, sizeof(Drop));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m >> cnt_have;
        --m;
        while (m--)
        {
            cin >> lost;
            if (lost > 0)
            {
                if (cnt_have > lost)
                {
                    D++;
                    cnt_have = lost;
                    Drop[i] = true;
                }
            }
            else
            {
                cnt_have = cnt_have + lost;
            }
        }
        T += cnt_have;
    }
    for (int i = 1; i <= n; i++)
    {
        if (Drop[i] & Drop[(i - 2 + n) % n + 1] & Drop[(i + n) % n + 1])
            E++;
    }
    cout << T << " " << D << " " << E;
    return 0;
}