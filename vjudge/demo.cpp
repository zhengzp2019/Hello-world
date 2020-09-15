#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;

int main()
{
    cin >> n;

    while (n--)
    {
        double a, b, c;
        double delta = 0;
        cin >> a >> b >> c;
        delta = b * b - 4 * a * c;
        if (delta == 0)
        {
            double x = (-b) / (2 * a);
            printf("x1=x2=%.5lf\n", x);
        }
        else if (delta > 0)
        {
            double x1, x2, t;
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 < x2)
            {
                t = x1;
                x1 = x2;
                x2 = t;
            }
            printf("x1=%.5lf;", x1);
            printf("x2=%.5lf\n", x2);
        }
        else
        {
            delta = -delta;
            double real, imagin1, imagin2, imagin;
            real = (-b) / (2 * a);
            imagin = sqrt(delta) / (2 * a);
            if(a>0)
            {
                imagin1 = imagin;
                imagin2 = -imagin;
            }
            else
            {
                imagin1 = -imagin;
                imagin2 = imagin;
            }
            printf("x1=%.5lf+%.5lfi;", real, imagin1);
            printf("x2=%.5lf%.5lfi\n", real, imagin2);
        }
    }
    return 0;
}