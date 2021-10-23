/*二叉树*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include ".general.h"
#include "StackLink.h"
#define NOINFO 0xDDF
typedef long ETypeBiT;

/*Structure Declaration*/
typedef struct BiTNode *BiTree;
struct BiTNode {
    ETypeBiT elem;
    BiTree left;
    BiTree right;
};

/*Typedef Override*/
#define long BiTree
#include "QueueLink.h"
#undef BiTree

/*Create*/
//层序创建
BiTree LevelCreateBiT(ETypeBiT arr[], Length len);
//先序创建(递归)
void rePreCreateBiT(BiTree *BT);
//先序创建
BiTree PreCreateBiT(ETypeBiT arr[], Length len);

/*Traverse*/
//前序遍历(递归)
void rePreTrav(BiTree BT);
//中序遍历(递归)
void reInTrav(BiTree BT);
//后序遍历(递归)
void rePostTrav(BiTree BT);
//前序遍历
void PreTrav(BiTree BT);
//中序遍历
void InTrav(BiTree BT);
//后序遍历
void PostTrav(BiTree BT);

#endif