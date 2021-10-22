#include "BinaryTree.h"

BiTree CreateBiTree(const int arr[], int len)
{
    int i = 0;
    LQueue Q = createLQueue();
    //first
    if(arr[i] == NOINFO || len < 1)
        return NULL;
    BiTree BT = (BiTree) malloc(sizeof(struct BiTNode));
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    AddLQ(Q, BT);
    //other

}
