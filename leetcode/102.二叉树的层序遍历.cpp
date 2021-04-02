/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> line;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int layer = 0;
        while (!q.empty())
        {
            int length = q.size();
            ans.push_back(line);
            for (int i = 0; i < length; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
                ans[layer].push_back(node->val);
            }
            layer++;
        }
        return ans;
    }
};
// @lc code=end
