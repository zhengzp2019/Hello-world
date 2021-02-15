/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int f_1 = 1,
            f_2 = 2,
            f_n;
        if (n == 1)
            return f_1;
        else if (n == 2)
            return f_2;
        else
            for (int i = 3; i <= n; i++)
            {
                f_n = f_1 + f_2;
                f_1 = f_2;
                f_2 = f_n;
            }
        return f_n;
    }
};
// @lc code=end
