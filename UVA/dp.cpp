#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int t = 1; //控制对拍次数一次
    while (t--)
    {
        system("makedata#.exe > input");
        system("my.exe <input> output_my");
        system("other.exe <input> output_other");
        cout << system("fc output_my output_other") << endl;
        if (system("fc output_my output_other")) //两文件内容相同返回0，不同返回1
        {
            break;
        }
    }
    if (t == -1)
    {
        cout << "no error" << endl;
    }
    else
    {
        cout << "error" << endl;
    }
    return 0;
}