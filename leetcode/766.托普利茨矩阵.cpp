/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        }
        return true;
    }
};
// @lc code=end
