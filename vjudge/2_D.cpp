#include <iostream>
using namespace std;
bool can_be_expression(int n,int a1,int a2,int a3,int a5,int a10,int a20);
int main()
{
    int a1, a2, a3, a5, a10, a20;
    cin >> a1 >> a2 >> a3 >> a5 >> a10 >> a20;
    int count = a1;
    int max = a1 + a2 * 2 + a3 * 3 + a5 * 5 + a10 * 10 + a20 * 20;
    for (int i = a1+1; i <= max; i++)
    {
        if (can_be_expression(i,a1,a2,a3,a5,a10,a20))
            count++;
    }
    cout << "Total=" << count;
    return 0;
}

bool can_be_expression(int n,int a1,int a2,int a3,int a5,int a10,int a20)
{
    while (n > 0 && a1 > 0)
    {
        if (a20 > 0 && n >= 20)
        {
            n -= 20;
            a20--;
        }
        else if (a10 > 10 && n >= 10)
        {
            n -= 10;
            a10--;
        }
        else if (a5 > 0 && n >= 5)
        {
            n -= 5;
            a5--;
        }
        else if (a3 > 0 && n >= 3)
        {
            n -= 3;
            a3--;
        }
        else if (a2 > 0  && n >= 2)
        {
            n -= 2;
            a2--;
        }
        else if (a1 > 0)
        {
            n -= 1;
            a1--;
        }
    }
    if (n == 0)
        return true;
    else
        return false;
}