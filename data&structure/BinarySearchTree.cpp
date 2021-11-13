#include <iostream>

using namespace std;

typedef int ElementType;
typedef TreeNode *Position, *SearchTree;

// ***********存储结构***********
struct TreeNode
{
    ElementType element;
    SearchTree left;
    SearchTree right;
};

// ****************ADT****************
SearchTree MakeEmpty(SearchTree T);             //置空查找树
Position Find(ElementType x, SearchTree T);     //查找元素值为x的位置
Position FindMin(SearchTree T);                 //查找树的最小值
Position FIndMax(SearchTree T);                 //查找树的最大值
SearchTree Insert(ElementType x, SearchTree T); //插入元素x并返回查找树
SearchTree Delete(ElementType x, SearchTree T); //删除元素x并返回查找树
ElementType Retrive(Position P);
// ***********************************

// ***************实现*****************
SearchTree MakeEmpty(SearchTree T)
{
    if (T)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        delete T;
    }
    return nullptr;
}

Position Find(ElementType x, SearchTree T)
{
    if (!T)
        return nullptr;
    if (x < T->element)
        return Find(T->left);
    else if (x > T->element)
        return Find(T->right);
    return T;
}

Position FindMin(SearchTree T)
{
    // 递归法
    if (!T)
        return nullptr;
    return T->left ? FindMin(T->left) : T;

    // 迭代法
    if (T)
        while (T->left)
            T = T->left;
    return T;
}

Position FindMax(SearchTree T)
{
    // 递归法
    if (!T)
        return nullptr;
    return T->right ? FindMax(T->right) : T;

    // 迭代法
    if (T)
        while (T->right)
            T = T->right;
    return T;
}

SearchTree Insert(ElementType x, SearchTree T)
{
    if (T == nullptr)
    {
        T = new TreeNode;
        if (T == nullptr)
            cerr << "Out of space" << endl;
        else
        {
            T->element = x;
            T->left = nullptr;
            T->right = nullptr;
        }
    }
    else
    {
        if (x < T->element)
            Insert(x, T->left);
        else if (x > T->element)
            Insert(x, T->right);
        // x==T->element说明元素已经存在，不需要进行任何操作
    }
    return T;
}

SearchTree Delete(ElementType x, SearchTree T)
{
    Position TmpCell;
    if (T == nullptr)
        cerr << "Element not found" << endl;
    else if (x < T->element)
        Delete(x, T->element);
    else if (x > T->element)
        Delete(x, T->right);
    else //找到需要删除的元素
    {
        if (T->left && T->right) //待删除元素有两个孩子
        {
            // 用右子树值最小的结点代替该结点
            TmpCell = FindMin(T->right);
            T->element = TmpCell->element;
            // 删除右子树中值最小的结点
            T->right = Delete(T->element, T->right);
        }
        else
        {
            TmpCell = T;
            if (T->left) //带删除结点有左孩子
                T = T->left;
            if (T->right) //带删除元素有右孩子
                T->T->right;
            delete T;
        }
    }
    return T;
}

ElementType Retrive(Position P)
{
    return P->element;
}

// *************************************