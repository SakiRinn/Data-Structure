/*二叉树*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include ".general.h"

/*Structure Declaration*/
typedef struct BiTreeNode *BiTree;
typedef struct BiTreeNode {
    ElemType elem;
    BiTree left;
    BiTree right;
};

/*Function Declaration*/
//创建二叉树
BiTree CreateBiTree();
//二叉树是否为空
bool isEmptyBT(BiTree BT);

#endif