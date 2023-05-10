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
    // attribute
    ElemType elem;
    BiTree left;
    BiTree right;
    // method
    ElemType* (*travPre)    (BiTree BT);
    ElemType* (*travIn)     (BiTree BT);
    ElemType* (*travPost)   (BiTree BT);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 层序创建
BiTree BiTree_init(ElemType arr[], ind_t len);
// 前序遍历 (递归)
void BiTree_reTravPre(BiTree BT);
// 中序遍历 (递归)
void BiTree_reTravIn(BiTree BT);
// 后序遍历 (递归)
void BiTree_reTravPost(BiTree BT);
/**
 * @brief 前序遍历
 *
 * @details 左子树入栈, 右子树出栈.
 * 一直循环左子树直到遍历到最末, 然后"尝试"一次右子树.
 * 如果尝试成功, 则循环新的左子树; 反之, 则出栈并回溯到出栈结点, 然后继续"尝试".
 * 左子树循环内打印, 遍历 (入栈) 一个打印一个.
 *
 * @param BT 输入二叉树
 * @return 动态数组
 */
ElemType* BiTree_travPre(BiTree BT);
/**
 * @brief 中序遍历
 *
 * @details 大体思路与前序相同.
 * 与前序唯一的区别: 将入栈时打印改为出栈时打印, 即"尝试"一次右子树打印一次.
 *
 * @param BT 输入二叉树
 * @return 动态数组
 */
ElemType* BiTree_travIn(BiTree BT);
/**
 * @brief 后序遍历
 *
 * @details 设计思路
 * 1. 与前序/中序相同, 栈S只用于记录第一个递归 (左子树) 经过的结点.
 *    因此, 后序无法只用栈S完成.
 * 2. 与中序唯一的区别: 后序输出右分支 (包括根结点) 的顺序与中序相反.
 *    增设一个print栈用于反转右分支的打印顺序, 然后在中序的基础上修改即可.
 * 3. 打印条件: 遍历完右分支的最末端. 至少打印一次.
 *    判断栈顶结点的右孩子是否为上一个已打印的结点. 若是, 则栈顶结点位于右分支上, 打印之.
 * 右分支: 右子树退化为线性表时的情况.
 *
 * @param BT 输入二叉树
 * @return 动态数组
 */
ElemType* BiTree_travPost(BiTree BT);
/**
 * @brief 后序遍历2
 *
 * @details 反转前序遍历
 * 前序遍历: 左 (打印) -> 根 -> 右.
 * 后序遍历: 左 -> 根 -> 右 (打印).
 * 后序遍历可视为前序遍历的反转, 即 "右 (打印) -> 根 -> 左" .
 * 利用栈, 将输出顺序也反转, 即得最终结果.
 *
 * @param BT 输入二叉树
 * @return 动态数组
 */
ElemType* BiTree_travPost2(BiTree BT);


#endif
