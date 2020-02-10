#include <cstdio>
#include <cstring>
#include <stack>
#define MAXN 100
using namespace std;

int main()
{
    //FILE *in = fopen("input", "r");
    //FILE *out = fopen("output", "w");
    int n;
    int kase = 0;
    scanf("%d", &n);
    //fgetc(in);
    getchar();
    while (n--)
    {
        char str[MAXN], ch;
        scanf("%s", str);
        printf("Case# %d: \n\t%s\n", ++kase, str);
        stack<char> s;
        int t = strlen(str);
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
        //printf("%s\n", flag ? "Yes" : "No");
    }
    //fclose(in);
    //fclose(out);
    return 0;
}