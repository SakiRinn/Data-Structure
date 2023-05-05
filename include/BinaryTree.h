/**
 * @file BinaryTree.h
 * @brief 二叉树
 *
 */
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include ".general.h"
#include "StackLink.h"
#include "QueueLink.h"

//-------------------------------------
// Structure Declaration
//-------------------------------------

// 初始化时使用, 数组中的EMPTY表示结点不存在 (空结点)
#define EMPTY 0xDDFDDF

typedef struct BiTreeNode *BiTree;
struct BiTreeNode {
    ElemType elem;
    BiTree left;
    BiTree right;
};

//-------------------------------------
// Method Declaration
//-------------------------------------

// 层序创建
BiTree BiTree_init(ElemType arr[], ind_t len);
// 先序创建 (递归)
BiTree BiTree_reInitPre(ElemType arr[], ind_t len);
// 先序创建
BiTree BiTree_initPre(ElemType arr[], ind_t len);

// 前序遍历 (递归)
void BiTree_reTravPre(BiTree BT);
// 中序遍历 (递归)
void BiTree_reTravIn(BiTree BT);
// 后序遍历 (递归)
void BiTree_reTravPost(BiTree BT);
// 前序遍历
void BiTree_travPre(BiTree BT);
// 中序遍历
void BiTree_travIn(BiTree BT);
// 后序遍历：根栈
void BiTree_travPost(BiTree BT);
// 后序遍历：记录结点
void BiTree_travPost2(BiTree BT);
// 后序遍历：先序倒序
void BiTree_travPost3(BiTree BT);


#endif

/* 递归转非递归：
 * 利用栈，左入栈右出栈。
 * 队列同理。 */
