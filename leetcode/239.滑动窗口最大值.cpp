/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        if (n <= 0 || k == 0)
            return ans;
        // int mmax = nums[0];
        for (int i = 0; i < n - k + 1; i++)
        {
            int mmax = nums[i];
            for (int j = 1; j < k; j++)
            {
                if (nums[i + j] > mmax)
                    mmax = nums[i + j];
            }
            ans.push_back(mmax);
        }
        /* for (int i = 1; i < k; i++)
        {
            if (mmax < nums[i])
                mmax = nums[i];
        }
        ans.push_back(mmax);
        for (int i = k; i < n; i++)
        {
            mmax = max(mmax, nums[i]);
            ans.push_back(mmax);
        } */
        return ans;
    }
};
// @lc code=end
