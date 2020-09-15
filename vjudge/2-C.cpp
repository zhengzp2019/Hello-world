#include <iostream>
using namespace std;
bool is_int(float n);
int main()
{
    int count = 0;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i <= c; i++)
    {
        if (is_int((c - b * i) / (float)a)&&(c-b*i)>=0)
            count++;
    }
    cout << count;
    return 0;
}

bool is_int(float n)
{
    if (n - (int)n == 0)
        return true;
    else
        return false;
}