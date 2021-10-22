#include "BinaryTree.h"

BiTree CreateBiTree(const ETypeBiT arr[], Length len)
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
    i++;
    //other
    BiTree BTptr;
    while (!isEmptyLQ(Q))
    {
        BTptr = DeleteLQ(Q);
        //left
        if(i >= len)
            break;
        else if(arr[i] != NOINFO)
        {
            BTptr->left = (BiTree) malloc(sizeof(struct BiTNode));
            BTptr->left->elem = arr[i];
            BTptr->left->left = BTptr->left->right = NULL;
            AddLQ(Q, BTptr->left);
            i++;
        }
        //right
        if(i >= len)
            break;
        else if(arr[i] != NOINFO)
        {
            BTptr->right = (BiTree) malloc(sizeof(struct BiTNode));
            BTptr->right->elem = arr[i];
            BTptr->right->left = BTptr->right->right = NULL;
            AddLQ(Q, BTptr->right);
            i++;
        }
    }
    return BT;
}
