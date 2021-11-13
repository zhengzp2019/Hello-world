#include <iostream>

using namespace std;

typedef int ElementType;
typedef TreeNode *PtrToNode, *Tree;

// *******树的存储结构********
struct TreeNode
{
    ElementType element;   //存储结点值
    PtrToNode FirstChild;  //指向第一个孩子
    PtrToNode NextSibling; //指向下一个兄弟
};
// ************************

// 先序遍历
void PreOrderTraverse(Tree T)
{
    if (!T)
        return;
    // 处理根节点
    for (PtrToNode p = T->FirstChild; p != nullptr; p = p->NextSibling)
        PreOrderTraverse(p);
}

// 后序遍历
void PostOrderTraverse(Tree T)
{
    if (!T)
        return;
    for (PtrToNode p = T->FirstChild; p != nullptr; p = p->NextSibling)
        PostOrderTraverse(p);
    // 处理根节点
}

