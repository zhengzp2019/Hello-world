/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return;
        stack<TreeNode *> stk;
        TreeNode *node = root;
        while (!stk.empty() || node != nulllptr)
        {
            while (node != nullptr)
            {
                // ans.push_back(node->val);
                stack.push(node);
                node = node->left;
            }
            node = stk.top();
            node = node->right;
        }
    }
};
// @lc code=end
