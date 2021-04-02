/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> line;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool isOrderLeft = true;
        while (!q.empty())
        {
            int size = q.size();
            deque<int> line;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (isOrderLeft)
                    line.push_back(node->val);
                else
                    line.push_front(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            ans.emplace_back(vector<int>{line.begin(), line.end()});
            isOrderLeft = !isOrderLeft;
        }
        return ans;
    }
};
// @lc code=end
