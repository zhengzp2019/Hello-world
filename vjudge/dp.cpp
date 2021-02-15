#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int t = 1;
    while (t--)
    {
        system("makedata#.exe > input");
        system("my.exe <input> output_my");
        system("other.exe <input> output_other");
        // system("fc output_my output_other");
        // cout << system("fc output_my output_other") << endl;
        if (system("fc output_my output_other")) //两文件内容相同返回0，不同返回1
        {
            cout << "有错误" << endl;
            break;
        }
    }
    return 0;
}