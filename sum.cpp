#include <iostream>

using namespace std;
int sum(int n); //求前n项和

int main()
{
    int n;
    cout << "请输入需要求的前n项和的n数\n";
    sum(n);
    cout << "前" << n << "项和为：" << sum << endl;
    return 0;
}

int sum(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        return sum(n - 1) + n;
    }
}