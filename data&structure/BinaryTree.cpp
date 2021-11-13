#include <iostream>
using namespace std;

typedef TreeNode *PtrToNode, *Tree;
typedef int ElementType;

// **********存储结构*********
struct TreeNode
{
    ElementType element;
    Tree left;
    Tree right;
};
// **************************

// 先序遍历
void PreOrderTraverse(Tree T)
{
    if (!T)
        return;
    // 处理根节点
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);
}

// 中序遍历
void InorderTraverse(Tree T)
{
    if (!T)
        return;
    InorderTraverse(T->left);
    //处理根节点
    InorderTraverse(T->right);
}

// 后序遍历
void PostOrderTraverse(Tree T)
{
    if (!T)
        return;
    PostOrderTraverse(T->left);
    PostOrderTraverse(T->right);
    // 处理根节点
}