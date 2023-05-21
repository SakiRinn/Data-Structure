#include "BinaryTree.h"

GENERIC_LINK(pointer)
GENERIC_QUEUE_LINK(pointer)
GENERIC_STACK_LINK(pointer)

BiTree BiTree_init(ElemType arr[], ind_t len) {
    // 队列：存储未生成左右孩子的结点的地址
    LQueue_pointer Q = LQueue_pointer_init();
    int i = 0;

    // 输入第一个数据
    // 1. 若为EMPTY，则为空树
    if (arr[i] == EMPTY || len < 1)
        return NULL;
    // 2. 若不为EMPTY，则分配根结点，并将其存入队列
    BiTree BT = (BiTree)malloc(sizeof(struct BiTreeNode));
    // attribute
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    // method
    BT->travPre     = BiTree_travPre;
    BT->travIn      = BiTree_travIn;
    BT->travPost    = BiTree_travPost;
    Q->add(Q, (pointer)BT);
    i++;

    // 若队列非空，则取出一个结点，建立其左右孩子
    BiTree tmpNode;
    while (!Q->isEmpty(Q)) {
        tmpNode = (BiTree)Q->remove(Q);
        // 1. 左孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tmpNode->left = (BiTree)malloc(sizeof(struct BiTreeNode));
            // attribute
            tmpNode->left->elem = arr[i];
            tmpNode->left->left = tmpNode->left->right = NULL;
            // method
            tmpNode->left->travPre      = BiTree_travPre;
            tmpNode->left->travIn       = BiTree_travIn;
            tmpNode->left->travPost     = BiTree_travPost;
            Q->add(Q, (pointer)tmpNode->left);
        }
        i++;
        // 2. 右孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tmpNode->right = (BiTree)malloc(sizeof(struct BiTreeNode));
            // attribute
            tmpNode->right->elem = arr[i];
            tmpNode->right->left = tmpNode->right->right = NULL;
            // method
            tmpNode->right->travPre     = BiTree_travPre;
            tmpNode->right->travIn      = BiTree_travIn;
            tmpNode->right->travPost    = BiTree_travPost;
            Q->add(Q, (pointer)tmpNode->right);
        }
        i++;
    }

    Q->delete(Q);
    return BT;
}

void BiTree_reTravPre(BiTree BT) {
    if (BT) {
        printf("%d ", BT->elem);
        BiTree_reTravPre(BT->left);
        BiTree_reTravPre(BT->right);
    }
}

void BiTree_reTravIn(BiTree BT) {
    if (BT) {
        BiTree_reTravIn(BT->left);
        printf("%d ", BT->elem);
        BiTree_reTravIn(BT->right);
    }
}

void BiTree_reTravPost(BiTree BT) {
    if (BT) {
        BiTree_reTravPost(BT->left);
        BiTree_reTravPost(BT->right);
        printf("%d ", BT->elem);
    }
}

ElemType* BiTree_travPre(BiTree BT) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init();
    BiTree curBT = BT;

    while (curBT || !S->isEmpty(S)) {
        // left
        while (curBT) {
            S->push(S, (pointer)curBT);
            printL->insertEnd(printL, curBT->elem);     // 前序: 入栈时print
            curBT = curBT->left;
        }
        // right
        curBT = (BiTree)S->pop(S);
        curBT = curBT->right;
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S);
    return array;
}

ElemType* BiTree_travIn(BiTree BT) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init();
    BiTree curBT = BT;

    while (curBT || !S->isEmpty(S)) {
        // left
        while (curBT) {
            S->push(S, (pointer)curBT);
            curBT = curBT->left;
        }
        // right
        curBT = (BiTree)S->pop(S);
        printL->insertEnd(printL, curBT->elem);         // 中序: 出栈时print
        curBT = curBT->right;
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S);
    return array;
}

ElemType* BiTree_travPost(BiTree BT) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init(), printS = LStack_pointer_init();
    BiTree curBT = BT, printBT = NULL;
    while (curBT || !S->isEmpty(S)) {
        // left
        while (curBT) {
            S->push(S, (pointer)curBT);
            curBT = curBT->left;
        }
        // right
        curBT = (BiTree)S->pop(S);
        printS->push(printS, (pointer)curBT);           // 后序: 出栈时放入print栈
        curBT = curBT->right;

        // print
        if (!curBT) {
            do {
                printBT = (BiTree)printS->pop(printS);
                printL->insertEnd(printL, printBT->elem);
            } while (!printS->isEmpty(printS) &&
                     ((BiTree)printS->top->elem)->right == printBT);
            printBT = NULL;
        }
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S); printS->delete(printS);
    return array;
}

ElemType* BiTree_travPost2(BiTree BT) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init(), printS = LStack_pointer_init();
    BiTree curBT = BT;

    while (curBT || !S->isEmpty(S)) {
        // right
        while (curBT) {
            S->push(S, (pointer)curBT);
            printS->push(printS, (pointer)curBT);     // (伪)前序: 入栈时放入print栈
            curBT = curBT->right;
        }
        // left
        curBT = (BiTree)S->pop(S);
        curBT = curBT->left;
    }

    // print in reverse
    while (!printS->isEmpty(printS))
        printL->insertEnd(printL, ((BiTree)printS->pop(printS))->elem);

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S); printS->delete(printS);
    return array;
}
