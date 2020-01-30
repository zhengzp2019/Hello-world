#include<iostream>
using namespace std;

int main()
{
    int have = 0, cnt_have, cnt_lost = 0, l, max_lost = 0, lable = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt_have;
        cnt_lost = 0;
        for (int j = 1; j <= m;j++)
        {
            cin >> l;
            cnt_lost += l;
        }
        have += cnt_have + cnt_lost;
        if(max_lost>cnt_lost)
        {
            max_lost = cnt_lost;
            lable = i;
        }
    }
    cout << have << " " << lable << " " << -max_lost << endl;
    return 0;
}