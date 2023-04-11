/*二叉树*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


#include ".general.h"
#include "StackLink.h"
#include "QueueLink.h"
#define EMPTY 0xDDF

//-------------------------------------
// Structure Declaration
//-------------------------------------
typedef struct BiTreeNode *BiTree;
struct BiTreeNode {
    ElemType elem;
    BiTree left;
    BiTree right;
};

//-------------------------------------
// Method Declaration
//-------------------------------------

/**
 * @brief 层序创建
 *
 * @param arr 数组，空结点用EMPTY表示
 * @param len arr的长度
 * @return BiTree
 */
BiTree BiTree_init(ElemType arr[], len_t len);
// 先序创建(递归)
BiTree BiTree_reInitPre(ElemType arr[], len_t len);
// 先序创建
BiTree BiTree_initPre(ElemType arr[], len_t len);

/*Traverse*/

// 前序遍历(递归)
void BiTree_reTravPre(BiTree BT);
// 中序遍历(递归)
void BiTree_reTravIn(BiTree BT);
// 后序遍历(递归)
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
