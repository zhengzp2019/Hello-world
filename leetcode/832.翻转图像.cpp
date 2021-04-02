/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> B(row, vector<int>(col, 1));
        for (int i = 0; i < row; i++)
        {
            reverse(A[i].begin(), A[i].end());
            for (int j = 0; j < col; j++)
                A[i][j] = A[i][j] ^ B[i][j];
        }
        return A;
    }
};
// @lc code=end
