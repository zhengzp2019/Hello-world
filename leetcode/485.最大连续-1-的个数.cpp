/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max_cnt = 0, cnt = 0;
        bool first = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==1)
                cnt++;
            else
            {
                max_cnt = max(cnt, max_cnt);
                cnt = 0;
            }
        }
        return max(max_cnt, cnt);
    }
};
// @lc code=end
