#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

set<string> dict;
int main()
{
    string s, buff;
    while (cin >> s)
    {
        //单词格式化
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = ' ';
            }
        }
        //单词入dict
        istringstream ss(s);
        while (ss >> buff)
        {
            dict.insert(buff);
        }
    }
    for (set<string>::iterator p = dict.begin(); p != dict.end(); p++)
    {
        cout << *p << '\n';
    }
    return 0;
}