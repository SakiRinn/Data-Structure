#include "BinaryTree.h"
#include ".general.h"
#include "QueueLink.h"
#include "StackLink.h"

GENERIC_LINK(BiTree)
GENERIC_QUEUE_LINK(BiTree)
GENERIC_STACK_LINK(BiTree)


BiTree BiTree_init(ElemType arr[], len_t len) {
    // 队列：存储未生成左右孩子的结点的地址
    LQueue_BiTree Q = LQueue_BiTree_init();
    int i = 0;

    // 输入第一个数据
    // 1. 若为EMPTY，则为空树
    if (arr[i] == EMPTY || len < 1)
        return NULL;
    // 2. 若不为EMPTY，则分配根结点，并将其存入队列
    BiTree BT = (BiTree)malloc(sizeof(struct BiTreeNode));
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    Q.add(Q, (BiTree)BT);
    i++;

    // 若队列非空，则取出一个结点，建立其左右孩子
    BiTree tempNode;
    while (!Q.isEmpty(Q)) {
        tempNode = (BiTree)Q.remove(Q);
        // 1. 左孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tempNode->left = (BiTree)malloc(sizeof(struct BiTreeNode));
            tempNode->left->elem = arr[i];
            tempNode->left->left = tempNode->left->right = NULL;
            Q.add(Q, (BiTree)tempNode->left);
        }
        i++;
        // 2. 右孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tempNode->right = (BiTree)malloc(sizeof(struct BiTreeNode));
            tempNode->right->elem = arr[i];
            tempNode->right->left = tempNode->right->right = NULL;
            Q.add(Q, (BiTree)tempNode->right);
        }
        i++;
    }

    Q.delete(Q);
    return BT;
}

BiTree _reInitPre(ElemType arr[], len_t len, BiTree BT) {
    return BT;
}


BiTree BiTree_reInitPre(ElemType arr[], len_t len) {
    int i = 0;

    // 输入第一个数据
    // 1. 若为EMPTY，则为空树
    if (arr[i] == EMPTY || len < 1)
        return NULL;
    // 2. 若不为EMPTY，则分配根结点
    BiTree BT = (BiTree)malloc(sizeof(struct BiTreeNode));
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    i++;

    // 递归：先左后右（先序）
    // _reInitPre(arr + i, len - 1);
    // _reInitPre(&(*BT)->right);
    // TODO:

    return BT;
}

BiTree BiTree_initPre(ElemType arr[], len_t len) {
    if (len < 1 || arr[0] == EMPTY)
        return NULL;
    int i = 0;
    LStack_BiTree S = LStack_BiTree_init();
    // first
    BiTree BT = (BiTree)malloc(sizeof(struct BiTreeNode));
    BiTree BTemp = BT;
    S.push(S, (BiTree)BTemp);
    BTemp->elem = arr[i];
    BTemp->left = BTemp->right = NULL;
    i++;
    // other
    while (i < len && !S.isEmpty(S)) {
        // left
        while (i < len && !BTemp->left) {
            if (arr[i] != EMPTY) {
                BTemp->left = (BiTree)malloc(sizeof(struct BiTreeNode));
                S.push(S, (BiTree)BTemp);
                BTemp = BTemp->left;
                BTemp->elem = arr[i];
                BTemp->left = BTemp->right = NULL;
                i++;
            } else {
                i++;
                break;
            }
        }
        // right
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            BTemp->right = (BiTree)malloc(sizeof(struct BiTreeNode));
            BTemp = BTemp->right;
            BTemp->elem = arr[i];
            BTemp->left = BTemp->right = NULL;
        } else
            BTemp = (BiTree)S.pop(S);
        i++;
    }
    S.delete(S);
    return BT;
}

void BiTree_reTravPre(BiTree BT) {
    if (BT) {
        printf("%ld ", BT->elem);
        BiTree_reTravPre(BT->left);
        BiTree_reTravPre(BT->right);
    }
}

void BiTree_reTravIn(BiTree BT) {
    if (BT) {
        BiTree_reTravIn(BT->left);
        printf("%ld ", BT->elem);
        BiTree_reTravIn(BT->right);
    }
}

void BiTree_reTravPost(BiTree BT) {
    if (BT) {
        BiTree_reTravPost(BT->left);
        BiTree_reTravPost(BT->right);
        printf("%ld ", BT->elem);
    }
}

void BiTree_travPre(BiTree BT) {
    LStack_BiTree S = LStack_BiTree_init();
    BiTree BTemp = BT;
    while (BTemp || !S.isEmpty(S)) {
        // left
        while (BTemp) {
            printf("%ld ", BTemp->elem);
            S.push(S, (BiTree)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = ((BiTree)S.pop(S))->right;
    }
}

void BiTree_travIn(BiTree BT) {
    LStack_BiTree S = LStack_BiTree_init();
    BiTree BTemp = BT;
    while (BTemp || !S.isEmpty(S)) {
        // left
        while (BTemp) {
            S.push(S, (BiTree)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)S.pop(S);
        printf("%ld ", BTemp->elem);
        BTemp = BTemp->right;
    }
}

void BiTree_travPost(BiTree BT) {
    LStack_BiTree S = LStack_BiTree_init(), SBrc = LStack_BiTree_init();
    BiTree BTemp = BT;
    while (BTemp || !S.isEmpty(S)) {
        // left
        while (BTemp) {
            S.push(S, (BiTree)BTemp);
            if (BTemp->left && BTemp->right)
                SBrc.push(SBrc, (BiTree)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)S.top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp) {
            BiTree BTbrc = (BiTree)SBrc.pop(SBrc);
            while (!S.isEmpty(S) && (BiTree)S.top->elem != BTbrc)
                printf("%ld ", ((BiTree)S.pop(S))->elem);
        }
    }
    S.delete(S);
    SBrc.delete(SBrc);
    // 一般结点出栈后再放入(查看栈顶)。
    // 有左右子树的结点，放入Branch栈中。
    // 遇到叶结点，弹出栈，直到栈顶为Branch的顶(弹出)为止。
}

void BiTree_travPost2(BiTree BT) {
    LStack_BiTree S = LStack_BiTree_init();
    BiTree BTemp = BT, BTprt = NULL;
    while (BTemp || !S.isEmpty(S)) {
        // left
        while (BTemp) {
            S.push(S, (BiTree)BTemp);
            BTemp = BTemp->left;
        }
        // right
        BTemp = (BiTree)S.top->elem;
        BTemp = BTemp->right;
        // output
        if (!BTemp || BTemp == BTprt) {
            BTprt = (BiTree)S.pop(S);
            printf("%ld ", BTprt->elem);
            BTemp = NULL;
        }
    }
    S.delete(S);
    // 共同点：输出完BTemp必须是NULL
    // 到叶结点时，输出且出栈，并用BTprt记录本次输出的结点。
    // 上一个结点的右指针与BTprt相同，说明已经输出完其右子树，故进行输出(即后序)。
}

void BiTree_travPost3(BiTree BT) {
    LStack_BiTree S = LStack_BiTree_init(), Sprt = LStack_BiTree_init();
    BiTree BTemp = BT;
    while (BTemp || !S.isEmpty(S)) {
        // right
        while (BTemp) {
            Sprt.push(Sprt, (BiTree)BTemp);
            S.push(S, (BiTree)BTemp);
            BTemp = BTemp->right;
        }
        // left
        BTemp = ((BiTree)S.pop(S))->left;
    }
    // output
    while (!Sprt.isEmpty(Sprt))
        printf("%ld ", ((BiTree)Sprt.pop(Sprt))->elem);
    S.delete(S);
    Sprt.delete(Sprt);
    // 先序遍历是：根-->左-->右，而后序遍历是：左-->右-->根。
    // 把先序遍历稍微修改变成：根-->右-->左，就发现它正好是后序遍历的倒序。
    // 把打印节点变成压入一个临时的栈中，结束后再对这个临时的栈依次弹栈打印节点即可。
}
