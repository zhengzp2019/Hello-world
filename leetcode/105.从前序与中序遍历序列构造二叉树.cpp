/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int preorderVal = preorder[i];
            TreeNode *node = stk.top();
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else
            {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex])
                {
                    node = stk.top();
                    stk.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end
