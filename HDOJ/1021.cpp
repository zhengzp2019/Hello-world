#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1e6 + 100;
int n;
ll f[N];

int main()
{
    f[0] = 7, f[1] = 11;
    int last = 1; //指向f数组的最后一个元素

    while (scanf("%d", &n) == 1)
    {
        if (!f[n])
        {
            for (int i = last; i <= n; i++)
                f[i + 1] = f[i - 1] + f[i];
            last = n;
        }
        printf(f[n] % 3 == 0 ? "Yes\n" : "No\n");
        // printf("%d %d\n", n, f[n]);
    }
    // for (int i = 0; i <= last; i++)
    //     printf("%d ", f[i]);
    return 0;
}