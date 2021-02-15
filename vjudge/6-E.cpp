// https://vjudge.net/contest/400708#problem/E
#include <iostream>
#include <vector>
// #include <cstring>
#include <string>
// #include <ctype.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    // char str[10100] = {'\0'};
    // scanf("%s", str);
    string str;
    cin >> str;
    vector<int> a(30, 0);
    /*int i;
    for (i = 0; i < 10100 && str[i] != '\0'; i++)
    {
        a[tolower(str[i]) - 'a']++;
    }*/
    for (auto &&ch : str)
    {
        if (ch >= 'A' && ch <= 'Z')
            a[ch - 'A']++;
        if (ch >= 'a' && ch <= 'b')
            a[ch - 'a']++;
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 26, sum = 0;
    for (int i = 0; a[i] != 0; i++, cnt--)
    {
        sum += a[i] * cnt;
    }
    cout << sum << endl;
    return 0;
}
