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
    //一般结点出栈后再放入(查看栈顶)。
    //有左右子树的结点，放入Branch栈中。
    //遇到叶结点，弹出栈，直到栈顶为Branch的顶(弹出)为止。
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
    //共同点：输出完BTemp必须是NULL
    //到叶结点时，输出且出栈，并用BTprt记录本次输出的结点。
    //上一个结点的右指针与BTprt相同，说明已经输出完其右子树，故进行输出(即后序)。
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
    //先序遍历是：根-->左-->右，而后序遍历是：左-->右-->根。
    //把先序遍历稍微修改变成：根-->右-->左，就发现它正好是后序遍历的倒序。
    //把打印节点变成压入一个临时的栈中，结束后再对这个临时的栈依次弹栈打印节点即可。
}
