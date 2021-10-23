#include "BinaryTree.h"

BiTree LevelCreateBiT(ETypeBiT arr[], Length len)
{
    int i = 0;
    LQueue Q = CreateLQueue();
    // first
    if (arr[i] == NOINFO || len < 1)
        return NULL;
    BiTree BT = (BiTree)malloc(sizeof(struct BiTNode));
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    AddLQ(Q, (ETypeBiT)BT);
    i++;
    // other
    BiTree BTptr;
    while (!isEmptyLQ(Q))
    {
        BTptr = (BiTree)DeleteLQ(Q);
        // left
        if (i >= len)
            break;
        else if (arr[i] != NOINFO)
        {
            BTptr->left = (BiTree)malloc(sizeof(struct BiTNode));
            BTptr->left->elem = arr[i];
            BTptr->left->left = BTptr->left->right = NULL;
            AddLQ(Q, (ETypeBiT)BTptr->left);
        }
        i++;
        // right
        if (i >= len)
            break;
        else if (arr[i] != NOINFO)
        {
            BTptr->right = (BiTree)malloc(sizeof(struct BiTNode));
            BTptr->right->elem = arr[i];
            BTptr->right->left = BTptr->right->right = NULL;
            AddLQ(Q, (ETypeBiT)BTptr->right);
        }
        i++;
    }
    RemoveLQueue(Q);
    return BT;
}

void rePreCreateBiT(BiTree *BT)
{
    // input
    ETypeBiT elem;
    printf("input: ");
    if (scanf("%ld", &elem) == 0)
    {
        printf("No Info.\n");
        while (getchar() != '\n');
        return;
    }
    // create
    *BT = (BiTree)malloc(sizeof(struct BiTNode));
    if (!*BT)
        exit(EXIT_FAILURE);
    (*BT)->elem = elem;
    rePreCreateBiT(&(*BT)->left);
    rePreCreateBiT(&(*BT)->right);
}

BiTree PreCreateBiT(ETypeBiT arr[], Length len)
{
    if (len < 1 || arr[0] == NOINFO)
        return NULL;
    int i = 0;
    LStack S = CreateLStack();
    // first
    BiTree BT = (BiTree)malloc(sizeof(struct BiTNode));
    BiTree BTemp = BT;
    LPush(S, (ETypeBiT)BTemp);
    BTemp->elem = arr[i];
    BTemp->left = BTemp->right = NULL;
    i++;
    // other
    while (i < len && !isEmptyLS(S))
    {
        // left
        while (i < len && !BTemp->left)
        {
            if (arr[i] != NOINFO)
            {
                BTemp->left = (BiTree)malloc(sizeof(struct BiTNode));
                LPush(S, (ETypeBiT)BTemp);
                BTemp = BTemp->left;
                BTemp->elem = arr[i];
                BTemp->left = BTemp->right = NULL;
                i++;
            }
            else 
            {
                i++;
                break;
            }
        }
        // right
        if (i >= len)
            break;
        if (arr[i] != NOINFO)
        {
            BTemp->right = (BiTree)malloc(sizeof(struct BiTNode));
            BTemp = BTemp->right;
            BTemp->elem = arr[i];
            BTemp->left = BTemp->right = NULL;
        }
        else
            BTemp = (BiTree)LPop(S);
        i++;
    }
    RemoveLStack(S);
    return BT;
}

void rePreTrav(BiTree BT)
{
    if (BT)
    {
        printf("%ld ", BT->elem);
        rePreTrav(BT->left);
        rePreTrav(BT->right);
    }
}

void reInTrav(BiTree BT)
{
    if (BT)
    {
        reInTrav(BT->left);
        printf("%ld ", BT->elem);
        reInTrav(BT->right);
    }
}

void rePostTrav(BiTree BT)
{
    if (BT)
    {
        rePostTrav(BT->left);
        rePostTrav(BT->right);
        printf("%ld ", BT->elem);
    }
}