#include "BinaryTree.h"
#include ".general.h"

BiTree BiTree_initByLevel(ElemType arr[], len_t len)
{
    int i = 0;
    LQueue Q = LQueue_init();
    // first
    if (arr[i] == EMPTY || len < 1)
        return NULL;
    BiTree BT = (BiTree) malloc(sizeof(struct BiTreeNode));
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    LQueue_add(Q, (ElemType) BT);
    i++;
    // other
    BiTree BTemp;
    while (!LQueue_isEmpty(Q))
    {
        BTemp = (BiTree) LQueue_delete(Q);
        // left
        if (i >= len)
            break;
        if (arr[i] != EMPTY)
        {
            BTemp->left = (BiTree) malloc(sizeof(struct BiTreeNode));
            BTemp->left->elem = arr[i];
            BTemp->left->left = BTemp->left->right = NULL;
            LQueue_add(Q, (ElemType) BTemp->left);
        }
        i++;
        // right
        if (i >= len)
            break;
        if (arr[i] != EMPTY)
        {
            BTemp->right = (BiTree) malloc(sizeof(struct BiTreeNode));
            BTemp->right->elem = arr[i];
            BTemp->right->left = BTemp->right->right = NULL;
            LQueue_add(Q, (ElemType) BTemp->right);
        }
        i++;
    }
    LQueue_remove(Q);
    return BT;
}

void BiTree_reInitByPre(BiTree *BT)
{
    // input
    ElemType elem;
    printf("input: ");
    if (scanf("%ld", &elem) == 0)
    {
        printf("No Info.\n");
        while (getchar() != '\n');
        return;
    }
    // create
    *BT = (BiTree)malloc(sizeof(struct BiTreeNode));
    if (!*BT)
        exit(EXIT_FAILURE);
    (*BT)->elem = elem;
    BiTree_reInitByPre(&(*BT)->left);
    BiTree_reInitByPre(&(*BT)->right);
}

BiTree BiTree_initByPre(ElemType arr[], len_t len)
{
    if (len < 1 || arr[0] == EMPTY)
        return NULL;
    int i = 0;
    LStack S = LStack_init();
    // first
    BiTree BT = (BiTree) malloc(sizeof(struct BiTreeNode));
    BiTree BTemp = BT;
    LStack_push(S, (ElemType) BTemp);
    BTemp->elem = arr[i];
    BTemp->left = BTemp->right = NULL;
    i++;
    // other
    while (i < len && !LStack_isEmpty(S))
    {
        // left
        while (i < len && !BTemp->left)
        {
            if (arr[i] != EMPTY)
            {
                BTemp->left = (BiTree) malloc(sizeof(struct BiTreeNode));
                LStack_push(S, (ElemType) BTemp);
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
        if (arr[i] != EMPTY)
        {
            BTemp->right = (BiTree) malloc(sizeof(struct BiTreeNode));
            BTemp = BTemp->right;
            BTemp->elem = arr[i];
            BTemp->left = BTemp->right = NULL;
        }
        else
            BTemp = (BiTree) LStack_pop(S);
        i++;
    }
    LStack_remove(S);
    return BT;
}

void BiTree_reTravPre(BiTree BT)
{
    if (BT)
    {
        printf("%ld ", BT->elem);
        BiTree_reTravPre(BT->left);
        BiTree_reTravPre(BT->right);
    }
}

void BiTree_reTravIn(BiTree BT)
{
    if (BT)
    {
        BiTree_reTravIn(BT->left);
        printf("%ld ", BT->elem);
        BiTree_reTravIn(BT->right);
    }
}

void BiTree_reTravPost(BiTree BT)
{
    if (BT)
    {
        BiTree_reTravPost(BT->left);
        BiTree_reTravPost(BT->right);
        printf("%ld ", BT->elem);
    }
}

void BiTree_travPre(BiTree BT)
{
    LStack S = LStack_init();
    BiTree BTemp = BT;
    while (BTemp || !LStack_isEmpty(S))
    {
        // left
        while (BTemp)
        {
            printf("%ld ", BTemp->elem);
            LStack_push(S, (ElemType) BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = ((BiTree) LStack_pop(S))->right;
    }
}

void BiTree_travIn(BiTree BT)
{
    LStack S = LStack_init();
    BiTree BTemp = BT;
    while (BTemp || !LStack_isEmpty(S))
    {
        // left
        while (BTemp)
        {
            LStack_push(S, (ElemType) BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree) LStack_pop(S);
        printf("%ld ", BTemp->elem);
        BTemp = BTemp->right;
    }
}

void BiTree_travPost(BiTree BT)
{
    LStack S = LStack_init(), SBrc = LStack_init();
    BiTree BTemp = BT;
    while (BTemp || !LStack_isEmpty(S))
    {
        // left
        while (BTemp)
        {
            LStack_push(S, (ElemType) BTemp);
            if (BTemp->left && BTemp->right)
                LStack_push(SBrc, (ElemType) BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree) S->top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp)
        {
            BiTree BTbrc = (BiTree) LStack_pop(SBrc);
            while (!LStack_isEmpty(S) && (BiTree) S->top->elem != BTbrc)
                printf("%ld ", ((BiTree) LStack_pop(S))->elem);
        }
    }
    LStack_remove(S);
    LStack_remove(SBrc);
    //一般结点出栈后再放入(查看栈顶)。
    //有左右子树的结点，放入Branch栈中。
    //遇到叶结点，弹出栈，直到栈顶为Branch的顶(弹出)为止。
}

void BiTree_travPost2(BiTree BT)
{
    LStack S = LStack_init();
    BiTree BTemp = BT, BTprt = NULL;
    while (BTemp || !LStack_isEmpty(S))
    {
        // left
        while (BTemp)
        {
            LStack_push(S, (ElemType) BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree) S->top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp || BTemp == BTprt)
        {
            BTprt = (BiTree) LStack_pop(S);
            printf("%ld ", BTprt->elem);
            BTemp = NULL;
        }
    }
    LStack_remove(S);
    //共同点：输出完BTemp必须是NULL
    //到叶结点时，输出且出栈，并用BTprt记录本次输出的结点。
    //上一个结点的右指针与BTprt相同，说明已经输出完其右子树，故进行输出(即后序)。
}

void BiTree_travPost3(BiTree BT)
{
    LStack S = LStack_init(), Sprt = LStack_init();
    BiTree BTemp = BT;
    while (BTemp || !LStack_isEmpty(S))
    {
        // right
        while (BTemp)
        {
            LStack_push(Sprt, (ElemType) BTemp);
            LStack_push(S, (ElemType) BTemp);
            BTemp = BTemp->right;
        }
        // left
        BTemp = ((BiTree) LStack_pop(S))->left;
    }
    // output
    while (!LStack_isEmpty(Sprt))
        printf("%ld ", ((BiTree) LStack_pop(Sprt))->elem);
    LStack_remove(S);
    LStack_remove(Sprt);
    //先序遍历是：根-->左-->右，而后序遍历是：左-->右-->根。
    //把先序遍历稍微修改变成：根-->右-->左，就发现它正好是后序遍历的倒序。
    //把打印节点变成压入一个临时的栈中，结束后再对这个临时的栈依次弹栈打印节点即可。
}
