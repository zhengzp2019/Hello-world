// https://vjudge.net/contest/402838#problem/B
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = 0;             //记录一轮最多割的韭菜数
    int first = 0, last = 1; //first指向每组序列的第一个元素，last指向最后一个
    while (last < n)
    {
        if (a[last - 1] >= a[last]) //重新开始割
        {
            if (max < last - first)
                max = last - first;
            first = last;
        }
        last++;
    }
    if (max < last - first)
        max = last - first;
    cout << max << endl;
    return 0;
}