#include <iostream>
using namespace std;

const int N = 300, K = 20;
int f[N][K];
int n, k;

int main()
{
    cin >> n >> k;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - j][j] + f[i - 1][j - 1];
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= i; j++)
    //     {
    //         if (j == 1)
    //             cout << endl;
    //         cout << f[i][j] << " ";
    //     }
    cout << f[n][k] << endl;
    return 0;
}