#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

typedef struct Matrix
{
    int c;
    int r;
} Matrix;

int n;
map<char, Matrix> M;
int Judgy(char left, char right);

int main()
{
    cin >> n;
    char ch;
    Matrix MT;
    //矩阵及维数初始化
    while (n--)
    {
        cin >> ch;
        cin >> M[ch].r >> M[ch].c;
    }

    //读入表达式
    string s;
    while (getline(cin, s))
    {
        istringstream ss;
        stack<char> s;
        char left, right;
        int sum = 0;
        while (ss >> right)
        {
            if (right == '(') //左括号
            {
                s.push(right);
            }
            else
            {
                if (Judgy(right, ')')) //右括号
                {
                    if (!Judgy(s.top(), '(')) //栈顶不是左括号，表达式错误
                    {
                        cout << "error" << endl;
                        break;
                    }
                    else //栈顶是左括号，弹出
                    {
                        s.pop();
                    }
                }
                else //字符
                {
                    left = s.top();
                    if (Judgy(s.top(), '(')) //栈顶是左括号，左值，入栈
                    {
                        s.push(right);
                    }
                    else //栈顶是字符，右值，求和
                    {
                        if (M[left].c != M[right].r) //不满足矩阵乘法
                        {
                            cout << "error" << endl;
                            break;
                        }
                        else //满足矩阵乘法
                        {
                            sum += M[left].r * M[left].c * M[right].c;
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
}

int Judgy(char left, char right)
{
    if (left == right)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}