#include <stdio.h>
#include <string.h>
#include <math.h>
const double a[10] = {12.01, 1.008, 16.00, 14.01};
char s[85];

int Judgy(int n, char *str); //判断第n位后面有几个连续的数字字符,返回数字个数k
int main()
{
    int T = 0;
    memset(s, 0, strlen(s));
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        double sum = 0;
        int n = strlen(s);
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else
            {
                int flag = Judgy(i + 1, s);
                switch (s[i])
                {
                case 'C':
                    if (flag)
                    {
                        for (int k = flag - 1; k >= 0; k--)
                        {
                            sum += a[0] * (s[i + flag - k] - '0') * pow(10, k);
                        }
                    }
                    else
                    {
                        sum += a[0];
                    }
                    break;
                case 'H':
                    if (flag)
                    {
                        for (int k = flag - 1; k >= 0; k--)
                        {
                            sum += a[1] * (s[i + flag - k] - '0') * pow(10, k);
                        }
                    }
                    else
                    {
                        sum += a[1];
                    }
                    break;
                case 'O':
                    if (flag)
                        for (int k = flag - 1; k >= 0; k--)
                        {
                            sum += a[2] * (s[i + flag - k] - '0') * pow(10, k);
                        }
                    else
                    {
                        sum += a[2];
                    }
                    break;
                case 'n':
                    if (flag)
                    {
                        for (int k = flag - 1; k >= 0; k--)
                        {
                            sum += a[3] * (s[i + flag - k] - '0') * pow(10, k);
                        }
                    }
                    else
                    {
                        sum += a[3];
                    }
                    break;
                default:
                    break;
                }
            }
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}

int Judgy(int n, char *str)
{
    if (str[n] >= '0' && str[n] <= '9')
    {
        return 1 + Judgy(n + 1, str);
    }
    else
    {
        return 0;
    }
}