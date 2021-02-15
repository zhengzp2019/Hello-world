// https://vjudge.net/contest/400708#problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
vector<int> a;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int L;
        cin >> L;
        a.push_back(L);
    }
    sort(a.begin(), a.end(), cmp);
    double sum = *a.begin();
    for (vector<int>::iterator p = a.begin() + 1; p != a.end(); p++)
    {
        sum = 2 * sqrt(sum * *p);
    }
    printf("%.3lf\n", sum);
    return 0;
}