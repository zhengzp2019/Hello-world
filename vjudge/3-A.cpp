// https://vjudge.net/contest/395078#problem/A
#include <iostream>
using namespace std;

int main()
{
    int a;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> a;
        int ai_1 = 1, ai_2 = 1, ai = 1;
        for (int i = 3; i <= a; i++)
        {
            ai = ai_1 + ai_2;
            ai_2 = ai_1;
            ai_1 = ai;
        }
        cout << ai << endl;
    }
    return 0;
}