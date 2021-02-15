// https://vjudge.net/contest/400708#problem/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct jewel
{
    int w;
    int v;
    // bool operator<(const jewel &j) const
    // {
    //     return (float)j.v / j.w < (float)v / w;
    // }
};

bool cmp(jewel a, jewel b)
{
    return (float)a.v / a.w > (float)b.v / b.w;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int M, N;
        cin >> M >> N;
        vector<jewel> a;
        while (N--)
        {
            jewel j;
            cin >> j.w >> j.v;
            a.push_back(j);
        }
        sort(a.begin(), a.end(), cmp);
        double value = 0;
        int W = 0;
        for (auto p = a.begin(); p != a.end(); p++)
        {
            // cout << (float)p->v / p->w << endl;
            if (W + p->w <= M)
            {
                value = value + p->v;
                W += p->w;
            }
            else
            {
                value += (p->v * (M - W) / (float)p->w);
                break;
            }
        }
        printf("%.2f\n", value);
    }
    return 0;
}