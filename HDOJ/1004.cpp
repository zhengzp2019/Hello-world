#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int N;
    while (cin >> N && N)
    {
        string col;
        map<string, int> c;
        while (N--)
        {
            cin >> col;
            c[col]++;
        }
        map<string, int>::iterator q = c.begin();
        for (map<string, int>::iterator p = c.begin(); p != c.end(); p++)
        {
            if (p->second > q->second)
                q = p;
        }
        cout << q->first << endl;
    }
    return 0;
}