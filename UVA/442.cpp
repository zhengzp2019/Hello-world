#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

int n;
typedef struct Matrix
{
    int r;
    int c;
    Matrix(int r = 0, int c = 0) : r(r), c(c) {}
} Matrix;
Matrix M[26];

int main()
{
    cin >> n;
    char ch;
    //矩阵及维数初始化
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        cin >> M[ch - 'A'].r >> M[ch - 'A'].c;
    }
    //读入表达式
    string str;
    while (cin >> str)
    {
        istringstream ss(str);
        stack<Matrix> s;
        char ch = 0;
        Matrix l, r;
        int sum = 0, ok = 1;
        while (ss >> ch)
        {
            if (ch == '(') //左括号
                continue;
            else
            {
                if (ch==')') //右括号
                {
                    r = s.top();
                    s.pop();
                    l = s.top();
                    s.pop();
                    if (l.c!=r.r) //不满足矩阵乘法
                    {
                        cout << "error" << endl;
                        ok = 0;
                        break;
                    }
                    else //满足矩阵乘法
                    {
                        sum += l.r * l.c * r.c;
                        l.c = r.c;
                        s.push(l);
                    }
                }
                else
                {
                    s.push(M[ch - 'A']);
                }
            }
        }
        if (ok)
            cout << sum << endl;
    }
    return 0;
}