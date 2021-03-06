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
    AddLQ(Q, (ETypeLQueue)BT);
    i++;
    // other
    BiTree BTemp;
    while (!isEmptyLQ(Q))
    {
        BTemp = (BiTree)DeleteLQ(Q);
        // left
        if (i >= len)
            break;
        if (arr[i] != NOINFO)
        {
            BTemp->left = (BiTree)malloc(sizeof(struct BiTNode));
            BTemp->left->elem = arr[i];
            BTemp->left->left = BTemp->left->right = NULL;
            AddLQ(Q, (ETypeLQueue)BTemp->left);
        }
        i++;
        // right
        if (i >= len)
            break;
        if (arr[i] != NOINFO)
        {
            BTemp->right = (BiTree)malloc(sizeof(struct BiTNode));
            BTemp->right->elem = arr[i];
            BTemp->right->left = BTemp->right->right = NULL;
            AddLQ(Q, (ETypeLQueue)BTemp->right);
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
    LPush(S, (ETypeLStack)BTemp);
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
                LPush(S, (ETypeLStack)BTemp);
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

void PreTrav(BiTree BT)
{
    LStack S = CreateLStack();
    BiTree BTemp = BT;
    while (BTemp || !isEmptyLS(S))
    {
        // left
        while (BTemp)
        {
            printf("%ld ", BTemp->elem);
            LPush(S, (ETypeLStack)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = ((BiTree)LPop(S))->right;
    }
}

void InTrav(BiTree BT)
{
    LStack S = CreateLStack();
    BiTree BTemp = BT;
    while (BTemp || !isEmptyLS(S))
    {
        // left
        while (BTemp)
        {
            LPush(S, (ETypeLStack)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)LPop(S);
        printf("%ld ", BTemp->elem);
        BTemp = BTemp->right;
    }
}

void PostTrav1(BiTree BT)
{
    LStack S = CreateLStack(), SBrc = CreateLStack();
    BiTree BTemp = BT;
    while (BTemp || !isEmptyLS(S))
    {
        // left
        while (BTemp)
        {
            LPush(S, (ETypeLStack)BTemp);
            if (BTemp->left && BTemp->right)
                LPush(SBrc, (ETypeLStack)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)S->Top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp)
        {
            BiTree BTbrc = (BiTree)LPop(SBrc);
            while (!isEmptyLS(S) && (BiTree)S->Top->elem != BTbrc)
                printf("%ld ", ((BiTree)LPop(S))->elem);
        }
    }
    RemoveLStack(S);
    RemoveLStack(SBrc);
    //??????????????????????????????(????????????)???
    //?????????????????????????????????Branch?????????
    //?????????????????????????????????????????????Branch??????(??????)?????????
}

void PostTrav2(BiTree BT)
{
    LStack S = CreateLStack();
    BiTree BTemp = BT, BTprt = NULL;
    while (BTemp || !isEmptyLS(S))
    {
        // left
        while (BTemp)
        {
            LPush(S, (ETypeLStack)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)S->Top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp || BTemp == BTprt)
        {
            BTprt = (BiTree)LPop(S);
            printf("%ld ", BTprt->elem);
            BTemp = NULL;
        }
    }
    RemoveLStack(S);
    //?????????????????????BTemp?????????NULL
    //??????????????????????????????????????????BTprt??????????????????????????????
    //??????????????????????????????BTprt????????????????????????????????????????????????????????????(?????????)???
}

void PostTrav3(BiTree BT)
{
    LStack S = CreateLStack(), Sprt = CreateLStack();
    BiTree BTemp = BT;
    while (BTemp || !isEmptyLS(S))
    {
        // right
        while (BTemp)
        {
            LPush(Sprt, (ETypeLStack)BTemp);
            LPush(S, (ETypeLStack)BTemp);
            BTemp = BTemp->right;
        }
        // left
        BTemp = ((BiTree)LPop(S))->left;
    }
    // output
    while (!isEmptyLS(Sprt))
        printf("%ld ", ((BiTree)LPop(Sprt))->elem);
    RemoveLStack(S);
    RemoveLStack(Sprt);
    //?????????????????????-->???-->??????????????????????????????-->???-->??????
    //???????????????????????????????????????-->???-->???????????????????????????????????????????????????
    //?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
}
