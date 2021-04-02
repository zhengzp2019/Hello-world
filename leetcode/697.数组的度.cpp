/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
                mp[nums[i]] = {1, i, i};
        }
        int maxNum = 0, minLen = 0;
        /* for (auto p = mp.begin(); p != mp.end(); p++)
        {
            if (maxNum < p->second[0])
            {
                maxNum = p->second[0];
                minLen = p->second[2] - p->second[1] + 1;
            }
            else if (maxNum == p->second[0])
            {
                if (minLen > p->second[2] - p->second[1] + 1)
                    minLen = p->second[2] - p->second[1] + 1;
            }
        } */
        for (auto &[_, vec] : mp)
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxNum == vec[0])
            {
                if (minLen > vec[2] - vec[1] + 1)
                    minLen = vec[2] - vec[1] + 1;
            }
        }
        return minLen;
    }
};
// @lc code=end
