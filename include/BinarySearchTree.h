/**
 * @file BinarySearchTree.h
 * @brief 二叉搜索树
 *
 * 通过对根结点进行面向对象包装, 实现C语言中的 "继承".
 * 除了biTree属性指向BiTree, 表征父类的对象; 其余属性均为函数指针, 表征派生类新定义的方法.
 * 因此, BiSTree的方法的首参数为BiSTree类 (自身), 但涉及到结点的返回值均为BiTree.
 *
 * @note 继承关系: BiSTree -> BiTree
 */
#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include ".general.h"
#include "BinaryTree.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

#define REMOVE_IS_LEFT_MAX

typedef struct BiSTreeNode *BiSTree;
struct BiSTreeNode {
    // inherited attribute
    ElemType elem;
    BiSTree left;
    BiSTree right;
    // inherited method
    ElemType*   (*travPre)  (BiSTree BT);
    ElemType*   (*travIn)   (BiSTree BT);
    ElemType*   (*travPost) (BiSTree BT);
    // method
    BiSTree     (*find)     (BiSTree BST, ElemType E);
    BiSTree     (*findMin)  (BiSTree BST);
    BiSTree     (*findMax)  (BiSTree BST);
    bool        (*insert)   (BiSTree BST, ElemType E);
    bool        (*remove)   (BiSTree BST, ElemType E);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

/**
 * @brief 查找元素
 *
 * 尾递归可以直接转换为for循环, 不需要借助栈; 反之亦然.
 * 因此, 该函数也可用递归实现. 代码如下
 * @code {.C}
 * BiSTree find(BiSTree BST, ElemType E) {
 *     if (!BST->root)
 *         return NULL;
 *     if (BST->elem < E)
 *         find(BST->left, E);
 *     else if (BST->elem > E)
 *         find(BST->right, E);
 *     return BST;
 * }
 * @endcode
 *
 * @param BST 待查找的二叉搜索树
 * @param E 元素值
 * @return BiTree 查找到的结点地址
 */
BiSTree BiSTree_find(BiSTree BST, ElemType E);
// 查找最小元素
BiSTree BiSTree_findMin(BiSTree BST);
// 查找最大元素
BiSTree BiSTree_findMax(BiSTree BST);
// 插入元素
bool BiSTree_insert(BiSTree BST, ElemType E);
// 删除元素
bool BiSTree_remove(BiSTree BST, ElemType E);

/**
 * @brief Inherited Declaration
 *
 * - 前序遍历
 * - 中序遍历
 * - 后序遍历
 */
ElemType* BiSTree_travPre(BiSTree BST);
ElemType* BiSTree_travIn(BiSTree BST);
ElemType* BiSTree_travPost(BiSTree BST);


#endif
