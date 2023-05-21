#include "BinarySearchTree.h"
#include "BinaryTree.h"

GENERIC_LINK(pointer)
GENERIC_QUEUE_LINK(pointer)
GENERIC_STACK_LINK(pointer)

BiTree BiSTree_init(ElemType arr[], ind_t len) {
    // 根结点
    BiSTree root = (BiSTree)malloc(sizeof(struct BiSTreeNode));
    root->elem      = arr[0];
    root->left      = NULL;
    root->right     = NULL;
    root->travPre   = BiSTree_travPre;
    root->travIn    = BiSTree_travIn;
    root->travPost  = BiSTree_travPost;
    root->find      = BiSTree_find;
    root->findMax   = BiSTree_findMax;
    root->findMin   = BiSTree_findMin;
    root->insert    = BiSTree_insert;
    root->remove    = BiSTree_remove;
    // 子结点
    for (int i = 1; i < len; i++)
        root->insert(root, arr[i]);
}

inline BiSTree BiSTree_free(BiSTree BST, BiSTree preBST, BiSTree newBST) {
    if (preBST->left == BST)
        preBST->left = newBST;
    else
        preBST->right = newBST;
    free(BST);
}

BiSTree BiSTree_find(BiSTree BST, ElemType E) {
    BiSTree curBST = BST;
    while (curBST && curBST->elem != E) {
        curBST = (curBST->elem < E) ? curBST->left : curBST->right;
    }
    return curBST;
}

BiSTree BiSTree_findMin(BiSTree BST) {
    if (!BST)
        return NULL;
    for (BiSTree cur = BST; cur->left; cur = cur->left)
        ;
    return BST;
}

BiSTree BiSTree_findMax(BiSTree BST) {
    if (!BST)
        return NULL;
    for (BiSTree cur = BST; cur->right; cur = cur->right)
        ;
    return BST;
}

bool BiSTree_insert(BiSTree BST, ElemType E) {
    BiSTree curBST = BST, preBST = NULL;
    bool isLeft;
    while (curBST) {
        if (curBST->elem < E) {
            preBST = BST;
            curBST = curBST->left;
            isLeft = true;
        }
        else if (curBST->elem > E) {
            preBST = BST;
            curBST = curBST->right;
            isLeft = false;
        } else
            /* found E */
            return false;
    }
    /* not found E, create */
    BiSTree newBST = (BiSTree)malloc(sizeof(struct BiSTreeNode));
    newBST->elem        = E;
    newBST->left        = NULL;
    newBST->right       = NULL;
    newBST->travPre     = BiSTree_travPre;
    newBST->travIn      = BiSTree_travIn;
    newBST->travPost    = BiSTree_travPost;
    newBST->find        = BiSTree_find;
    newBST->findMax     = BiSTree_findMax;
    newBST->findMin     = BiSTree_findMin;
    newBST->insert      = BiSTree_insert;
    newBST->remove      = BiSTree_remove;
    if (isLeft)
        preBST->left = newBST;
    else
        preBST->right = newBST;
    return true;
}

bool BiSTree_remove(BiSTree BST, ElemType E) {
    BiSTree curBST = BST, preBST = NULL;
    while (curBST) {
        if (curBST->elem < E) {
            preBST = curBST;
            curBST = curBST->left;
        } else if (curBST->elem > E) {
            preBST = curBST;
            curBST = curBST->right;
        } else {
            /* found E, delete */
            if (curBST->left && curBST->right) {
                #if defined(REMOVE_IS_LEFT_MAX)
                // 方法1: 取左子树的最大元素
                BiSTree tmpBST = curBST->left->findMax(curBST->left);
                #else
                // 方法2: 取右子树的最小元素
                BiSTree tmpBST = curBST->right->findMin(curBST->right);
                #endif
                tmpBST->left = curBST->left;
                tmpBST->right = curBST->right;
                BiSTree_free(curBST, preBST, tmpBST);
            } else if (curBST->left)
                BiSTree_free(curBST, preBST, curBST->left);
            else if (curBST->right)
                BiSTree_free(curBST, preBST, curBST->right);
            else
                BiSTree_free(curBST, preBST, NULL);
            return true;
        }
    }
    /* not found E */
    return false;
}

//-------------------------------------
// Inheritance
//-------------------------------------

ElemType* BiSTree_travPre(BiSTree BST) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init();
    BiSTree curBST = BST;

    while (curBST || !S->isEmpty(S)) {
        while (curBST) {
            S->push(S, (pointer)curBST);
            printL->insertEnd(printL, curBST->elem);
            curBST = curBST->left;
        }
        curBST = (BiSTree)S->pop(S);
        curBST = curBST->right;
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S);
    return array;
}

ElemType* BiSTree_travIn(BiSTree BST) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init();
    BiSTree curBST = BST;

    while (curBST || !S->isEmpty(S)) {
        // left
        while (curBST) {
            S->push(S, (pointer)curBST);
            curBST = curBST->left;
        }
        // right
        curBST = (BiSTree)S->pop(S);
        printL->insertEnd(printL, curBST->elem);
        curBST = curBST->right;
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S);
    return array;
}

ElemType* BiSTree_travPost(BiSTree BST) {
    Link printL = Link_init();
    LStack_pointer S = LStack_pointer_init(), printS = LStack_pointer_init();
    BiSTree curBST = BST, printBST = NULL;
    while (curBST || !S->isEmpty(S)) {
        // left
        while (curBST) {
            S->push(S, (pointer)curBST);
            curBST = curBST->left;
        }
        // right
        curBST = (BiSTree)S->pop(S);
        printS->push(printS, (pointer)curBST);
        curBST = curBST->right;

        // print
        if (!curBST) {
            do {
                printBST = (BiSTree)printS->pop(printS);
                printL->insertEnd(printL, printBST->elem);
            } while (!printS->isEmpty(printS) &&
                     ((BiSTree)printS->top->elem)->right == printBST);
            printBST = NULL;
        }
    }

    ElemType* array = printL->toArray(printL);
    printL->delete(printL);
    S->delete(S); printS->delete(printS);
    return array;
}
