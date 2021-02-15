/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode *left, TreeNode *right)
    {

        queue<TreeNode *> queue1, queue2;
        queue1.push(left);
        queue2.push(right);
        while (!queue1.empty() && !queue2.empty())
        {
            auto node1 = queue1.front(), node2 = queue2.front();
            queue1.pop();
            queue2.pop();
            if (node1 == nullptr && node2 == nullptr)
                continue;
            if (node1 == nullptr || node2 == nullptr)
                return false;
            if (node1->val == node2->val)
            {
                queue1.push(node1->left);
                queue1.push(node1->right);
                queue2.push(node2->right);
                queue2.push(node2->left);
            }
            else
                return false;
        }
        return queue1.empty() && queue2.empty();
    }
};
// @lc code=end
