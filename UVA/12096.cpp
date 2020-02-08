#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <stack>

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache; //把集合映射成为ID
vector<Set> Setcache;  //根据ID取集合
stack<int> s;

int ID(Set x);           //计算集合x的ID
Set AorB(Set A, Set B);  //或操作
Set AandB(Set A, Set B); //与操作

int main()
{
    int T;
    //ifstream in("12096_in.txt");
    //ofstream out("12096_out.txt");
    cin >> T;
    while (T--)
    {
        IDcache.clear();
        Setcache.clear();
        int n;
        cin >> n;
        string op;
        while (n--)
        {
            cin >> op;
            if (op[0] == 'P')
            {
                s.push(ID(Set()));
            }
            else
            {
                if (op[0] == 'D')
                {
                    s.push(s.top());
                }
                else
                {
                    Set x1 = Setcache[s.top()];
                    s.pop();
                    Set x2 = Setcache[s.top()];
                    s.pop();
                    Set x;
                    if (op[0] == 'U')
                    {
                        x = AorB(x1, x2);
                    }
                    if (op[0] == 'I')
                    {
                        x = AandB(x1, x2);
                    }
                    if (op[0] == 'A')
                    {
                        x2.insert(ID(x1));
                        x = x2;
                    }
                    s.push(ID(x));
                }
            }
            cout << Setcache[s.top()].size() << '\n';
        }
        cout << "***" << endl;
    }
    //in.close();
    //out.close();
    return 0;
}

int ID(Set x)
{
    if (IDcache.count(x))
    {
        return IDcache[x];
    }
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

Set AorB(Set A, Set B)
{
    for (Set::iterator p = B.begin(); p != B.end(); p++)
    {
        if (A.find(*p) == A.end())
        {
            A.insert(*p);
        }
    }
    return A;
}

Set AandB(Set A, Set B)
{
    int na = A.size();
    int nb = B.size();
    if (!na || !nb)
    {
        return Set();
    }
    Set s;
    for (Set::iterator p = B.begin(); p != B.end(); p++)
    {
        if (A.find(*p) != A.end())
        {
            s.insert(*p);
        }
    }
    return s;
}