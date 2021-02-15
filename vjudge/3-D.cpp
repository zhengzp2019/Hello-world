#include <iostream>
using namespace std;

float expression();      //计算距离运算符最近的表达式的值
bool isOperand(char ch); //判断字符ch是不是运算符

int main()
{
    printf("%f\n", expression());
    return 0;
}

float expression()
{
    char ch = '0';
    while ((ch = cin.peek()))
    {
        if (ch == ' ')
            cin.get();
        else
            break;
    }
    if (isOperand(ch)) //操作符
    {
        cin.get();
        switch (ch)
        {
        case '+':
            return expression() + expression();
            break;
        case '*':
            return expression() * expression();
            break;
        case '-':
            return expression() - expression();
            break;
        case '/':
            return expression() / expression();
            break;
        default:
            break;
        }
    }
    else //操作数
    {
        float ans;
        scanf("%f", &ans);
        return ans;
    }
    return 0;
}

bool isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}