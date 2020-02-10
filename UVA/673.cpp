#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 1000
using namespace std;
void read(char *str, int *n); //读取每行的的字符串

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        char str[MAXN], ch;
        stack<char> s;
        int t = 0;
        read(str, &t);
        int flag = 1;
        //扫描字符串
        for (int i = 0; i < t; i++)
        {
            sscanf(&str[i], "%c", &ch);
            switch (ch)
            {
            case '(':
                s.push(ch);
                break;
            case '[':
                s.push(ch);
                break;
            case ')':
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                    flag = 0;
                break;
            case ']':
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else
                    flag = 0;
                break;
            }
            if (!flag)
                break;
        }
        if (!s.empty())
            flag = 0;
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}

void read(char str[], int *n)
{
    char ch;
    while ((ch = getchar()) && ch != '\n')
    {
        str[*n] = ch;
        (*n)++;
    }
}