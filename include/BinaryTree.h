/*二叉树*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include ".general.h"
#include "StackLink.h"
#include "QueueLink.h"
#define NOINFO 0xDDF

/*Structure Declaration*/
typedef struct BiTNode *BiTree;
typedef struct BiTNode {
    ElemType elem;
    BiTree left;
    BiTree right;
};

/*Function Declaration*/
//创建二叉树
BiTree CreateBiTree(const int arr[], int len);
//二叉树是否为空
bool isEmptyBT(BiTree BT);

/*Recursion*/
//前序遍历(递归)
void rePreTrav(BiTree BT);
//中序遍历(递归)
void reInTrav(BiTree BT);
//后序遍历(递归)
void rePostTrav(BiTree BT);

/*Non Recursion*/
//前序遍历
void PreTrav(BiTree BT);
//中序遍历
void InTrav(BiTree BT);
//后序遍历
void PostTrav(BiTree BT);

#endif