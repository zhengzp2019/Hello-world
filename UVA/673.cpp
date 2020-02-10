#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 100
using namespace std;
void read(char *str, int *n); //读取每行的的字符串
FILE *in = fopen("input", "r");
FILE *out = fopen("output", "w");

int main()
{
    int n;
    fscanf(in, "%d", &n);
    fgetc(in);
    //getchar();
    while (n--)
    {
        char str[MAXN], ch;
        stack<char> s;
        int t = 0;
        read(str, &t);
        //printf("Case# %d: \n\t%s\n", ++kase, str);
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
        fprintf(out, "%s\n", flag ? "Yes" : "No");
    }
    fclose(in);
    fclose(out);
    return 0;
}

void read(char *str, int *n)
{
    char ch;
    while ((ch = fgetc(in)) && ch != '\n')
    {
        *(str++) = ch;
        (*n)++;
    }
}