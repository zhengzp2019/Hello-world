#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> s1 = {1, 2, 3, 4, 5}, s2 = {1, 2, 3};
    set<int> s;
    for (set<int>::iterator p = s1.begin(); p != s1.end(); p++)
    {
        if (s2.find(*p) != s2.end())
        {
            s.insert(*p);
        }
    }
    for (set<int>::iterator p = s.begin(); p != s.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
    return 0;
}