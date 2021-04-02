/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[j][i] = matrix[i][j];
        return ans;
    }
};
// @lc code=end
