/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size();
        int n = nums[0].size();
        if (n * m != r * c)
            return nums;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int x = 0; x < n * m; x++)
            ans[x / c][x % c] = nums[x / n][x % n];
        return ans;
    }
};
// @lc code=end
