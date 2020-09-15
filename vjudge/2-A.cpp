#include <iostream>
using namespace std;
int main()
{
    int n;
    int max = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if ((i + j) % 2 == 0)
            {
                for (int k = 0; k <= n; k++)
                {
                    if ((j + k) % 3 == 0 && (i + j + k) % 5 == 0)
                        if ((i + j + k) > max)
                            max = i + j + k;
                }
            }
        }
    cout << max << endl;
    return 0;
}