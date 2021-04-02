#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 100;
int m;

bool cmp(PII &a, PII &b)
{
    return a.first < b.first;
}

int main()
{
    scanf("%d", &m);
    PII a[N];

    for (int i = 0; i < m; i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + m, cmp);

    int sum = 0;
    int big = 0;
    int mx;
    for (int i = 0; i < m; i++)
        if (a[i].second == 1)
            sum++;

    mx = sum;
    for (int i = 0; i < m; i++)
        printf("%d-->%d\n", a[i].first, a[i].second);
    for (int i = 0; i < m; i++)
    {
        a[i].second == 0 ? sum++ : sum--;
        if (mx <= sum)
        {
            mx = sum;
            big = i + 1;
        }
    }
    printf("%d\n", a[big].first);
    return 0;
}