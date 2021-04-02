/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        if (n <= 0)
            return nullptr;
        stack<TreeNode *> stk;
        int inorderIndex = n - 1;
        TreeNode *root = new TreeNode(postorder[n - 1]);
        stk.push(root); 
        for (int i = n - 2; i >= 0; i--)
        {
            int postorderValue = postorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->right = new TreeNode(postorderValue);
                stk.push(node->right);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postorderValue);
                stk.push(node->left);
            }
        }
        return root;
    }
};
// @lc code=end
