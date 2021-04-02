/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        quick_sort(nums, 0, nums.size()-1);
    }
    
    void quick_sort(vector<int> &q, int l, int r)
    {
        if (l >= r)
            return;
        int x = q[l + r >> 1], i = l - 1, j = r + 1;
        while (i < j)
        {
            do
                i++;
            while (q[i] < x);
            do
                j--;
            while (q[j] > x);
            if (i < j)
                swap(q[i], q[j]);
        }
        quick_sort(q, l, j);
        quick_sort(q, j + 1, r);
    }
};
// @lc code=end
