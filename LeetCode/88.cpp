#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, cnt = 1;
    vector<int>::iterator first = nums1.begin(), second = nums2.begin();
    while (second != nums2.end()&&cnt<=m)
    {
        if (*first < *second)
        {
            first++;
            cnt++;
        }
        else
        {
            first = nums1.insert(first, *second);
            first++;
            second++;
        }
    }
    if(cnt>m)
    {
        nums1.insert(first, second, nums2.end());
    }
    for (auto it = nums1.begin(); it != nums1.end(); it++)
    {
        cout << *it << '\n';
    }
    return 0;
}