#include "BinaryTree.h"
#include <stdio.h>
#include <sys/types.h>
#include ".general.h"
#include "QueueLink.h"
#include "StackLink.h"

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
    BT->elem = arr[i];
    BT->left = BT->right = NULL;
    Q->add(Q, (pointer)BT);
    i++;

    // 若队列非空，则取出一个结点，建立其左右孩子
    BiTree tempNode;
    while (!Q->isEmpty(Q)) {
        tempNode = (BiTree)Q->remove(Q);
        // 1. 左孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tempNode->left = (BiTree)malloc(sizeof(struct BiTreeNode));
            tempNode->left->elem = arr[i];
            tempNode->left->left = tempNode->left->right = NULL;
            Q->add(Q, (pointer)tempNode->left);
        }
        i++;
        // 2. 右孩子
        if (i >= len)
            break;
        if (arr[i] != EMPTY) {
            tempNode->right = (BiTree)malloc(sizeof(struct BiTreeNode));
            tempNode->right->elem = arr[i];
            tempNode->right->left = tempNode->right->right = NULL;
            Q->add(Q, (pointer)tempNode->right);
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

void BiTree_travPre(BiTree BT) {
    LStack_pointer S = LStack_pointer_init();
    BiTree curBT = BT;
    while (curBT || !S->isEmpty(S)) {
        // left
        while (curBT) {
            S->push(S, (pointer)curBT);
            printf("%d ", curBT->elem);         // 前序: 入栈时print
            curBT = curBT->left;
        }
        // right
        curBT = (BiTree)S->pop(S);
        curBT = curBT->right;
    }
    S->delete(S);
}

void BiTree_travIn(BiTree BT) {
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
        printf("%d ", curBT->elem);             // 中序: 出栈时print
        curBT = curBT->right;
    }
    S->delete(S);
}

void BiTree_travPost(BiTree BT) {
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
        printS->push(printS, (pointer)curBT);        // 后序: 出栈时放入print栈
        curBT = curBT->right;
        // print
        if (!curBT) {
            do {
                printBT = (BiTree)printS->pop(printS);
                printf("%d ", printBT->elem);
            } while (!printS->isEmpty(printS) &&
                     ((BiTree)printS->top->elem)->right == printBT);
            printBT = NULL;
        }
    }
    S->delete(S);
}

void BiTree_travPost2(BiTree BT) {
    LStack_pointer S = LStack_pointer_init(), print_S = LStack_pointer_init();
    BiTree curBT = BT;
    while (curBT || !S->isEmpty(S)) {
        // right
        while (curBT) {
            S->push(S, (pointer)curBT);
            print_S->push(print_S, (pointer)curBT);    // (伪)前序: 入栈时放入print栈
            curBT = curBT->right;
        }
        // left
        curBT = (BiTree)S->pop(S);
        curBT = curBT->left;
    }
    // print in reverse
    while (!print_S->isEmpty(print_S))
        printf("%d ", ((BiTree)print_S->pop(print_S))->elem);
    S->delete(S);
}
