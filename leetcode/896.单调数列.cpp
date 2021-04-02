/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        /*         vector<int> B = A;
        sort(B.begin(), B.end());
        bool one = B == A;
        int n = A.size();
        for (int i = 0; i < n / 2; i++)
            swap(B[i], B[n - 1 - i]);
        bool two = B == A;
        return one || two; */
        bool inc = true, dec = true;
        int n = A.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] < A[i + 1])
                dec = false;
            if (A[i] > A[i + 1])
                inc = false;
        }
        return dec || inc;
    }
};
// @lc code=end
