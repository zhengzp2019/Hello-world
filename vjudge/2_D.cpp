// https://vjudge.net/contest/393679#problem/D
// 砝码称重
#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
    int a1, a2, a3, a5, a10, a20;
    cin >> a1 >> a2 >> a3 >> a5 >> a10 >> a20;
    for (int a = 0; a <= a1; a++)
        for (int b = 0; b <= a2; b++)
            for (int c = 0; c <= a3; c++)
                for (int d = 0; d <= a5; d++)
                {
                    for (int e = 0; e <= a10; e++)
                    {
                        for (int f = 0; f <= a20; f++)
                        {
                            s.insert(a * 1 + b * 2 + c * 3 + d * 5 + e * 10 + f * 20);
                        }
                    }
                }
    cout << "Total=" << s.size() - 1;
    return 0;
}