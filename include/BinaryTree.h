/*二叉树*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include ".general.h"
#include "StackLink.h"
#define NOINFO 0xDDF
typedef int ETypeBiT;

/*Structure Declaration*/
typedef struct BiTNode *BiTree;
struct BiTNode {
    ETypeBiT elem;
    BiTree left;
    BiTree right;
};

/*Override Typedef*/
#define long BiTree
#include "QueueLink.h"
#undef long

/*Function Declaration*/
//创建二叉树
BiTree CreateBiTree(const ETypeBiT arr[], Length len);
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