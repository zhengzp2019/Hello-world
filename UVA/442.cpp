#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <sstream>
#include <fstream>
using namespace std;

int n;
map<char, int> row, column;
int Judgy(char left, char right);

int main()
{
    fstream in("442_in.txt");
    fstream out("442_out.txt");
    in >> n;
    char ch;
    //矩阵及维数初始化
    while (n--)
    {
        in >> ch;
        in >> row[ch] >> column[ch];
    }
    //读入表达式
    string str;
    while (in >> str)
    {
        istringstream ss(str);
        stack<char> s;
        char left = 0, right = 0;
        int sum = 0;
        while (ss >> right)
        {
            if (right == '(') //左括号
                s.push(right);
            else
            {
                if (Judgy(right, ')')) //右括号
                {
                    if (!Judgy(s.top(), '(')) //栈顶不是左括号，表达式错误
                    {
                        out << "error" << endl;
                        break;
                    }
                    else //栈顶是左括号，弹出
                        s.pop();
                }
                else //字符
                {
                    if (s.empty() || Judgy(s.top(), '(')) //栈顶是左括号，左值，入栈
                        s.push(right);
                    else //栈顶是字符，右值，求和
                    {
                        left = s.top();
                        s.pop();
                        if (column[left] != row[right]) //不满足矩阵乘法
                        {
                            out << "error" << endl;
                            break;
                        }
                        else //满足矩阵乘法
                            sum += row[left] * column[left] * column[right];
                    }
                }
            }
        }
        out << sum << endl;
    }
    in.close();
    out.close();
    return 0;
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