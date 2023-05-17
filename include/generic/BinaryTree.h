/**
 * @file generic/BinaryTree.h
 * @brief 泛型二叉树
 *
 * @par Macro Dependency
 * @code {.C}
 * GENERIC_LINK(elem_t)
 * GENERIC_LINK(pointer)
 * GENERIC_QUEUE_LINK(pointer)
 * GENERIC_STACK_LINK(pointer)
 * @endcode
 */
#ifndef GENERIC_BITREE
#define GENERIC_BITREE(elem_t)                                                 \
    typedef struct BiTreeNode_##elem_t *BiTree_##elem_t;                       \
    struct BiTreeNode_##elem_t {                                               \
        elem_t elem;                                                           \
        BiTree_##elem_t left;                                                  \
        BiTree_##elem_t right;                                                 \
        elem_t *(*travPre)(BiTree_##elem_t BT);                                \
        elem_t *(*travIn)(BiTree_##elem_t BT);                                 \
        elem_t *(*travPost)(BiTree_##elem_t BT);                               \
    };                                                                         \
    static elem_t *BiTree_##elem_t##_travPre(BiTree_##elem_t BT) {             \
        Link_##elem_t printL = Link_##elem_t##_init();                         \
        LStack_pointer S = LStack_pointer_init();                              \
        BiTree_##elem_t curBT = BT;                                            \
        while (curBT || !S->isEmpty(S)) {                                      \
            while (curBT) {                                                    \
                S->push(S, (pointer)curBT);                                    \
                printL->insertEnd(printL, curBT->elem);                        \
                curBT = curBT->left;                                           \
            }                                                                  \
            curBT = (BiTree_##elem_t)S->pop(S);                                \
            curBT = curBT->right;                                              \
        }                                                                      \
        elem_t *array = printL->toArray(printL);                               \
        printL->delete (printL);                                               \
        S->delete (S);                                                         \
        return array;                                                          \
    }                                                                          \
    static elem_t *BiTree_##elem_t##_travIn(BiTree_##elem_t BT) {              \
        Link_##elem_t printL = Link_##elem_t##_init();                         \
        LStack_pointer S = LStack_pointer_init();                              \
        BiTree_##elem_t curBT = BT;                                            \
        while (curBT || !S->isEmpty(S)) {                                      \
            while (curBT) {                                                    \
                S->push(S, (pointer)curBT);                                    \
                curBT = curBT->left;                                           \
            }                                                                  \
            curBT = (BiTree_##elem_t)S->pop(S);                                \
            printL->insertEnd(printL, curBT->elem);                            \
            curBT = curBT->right;                                              \
        }                                                                      \
        elem_t *array = printL->toArray(printL);                               \
        printL->delete (printL);                                               \
        S->delete (S);                                                         \
        return array;                                                          \
    }                                                                          \
    static elem_t *BiTree_##elem_t##_travPost(BiTree_##elem_t BT) {            \
        Link_##elem_t printL = Link_##elem_t##_init();                         \
        LStack_pointer S = LStack_pointer_init(),                              \
                       printS = LStack_pointer_init();                         \
        BiTree_##elem_t curBT = BT, printBT = NULL;                            \
        while (curBT || !S->isEmpty(S)) {                                      \
            while (curBT) {                                                    \
                S->push(S, (pointer)curBT);                                    \
                curBT = curBT->left;                                           \
            }                                                                  \
            curBT = (BiTree_##elem_t)S->pop(S);                                \
            printS->push(printS, (pointer)curBT);                              \
            curBT = curBT->right;                                              \
            if (!curBT) {                                                      \
                do {                                                           \
                    printBT = (BiTree_##elem_t)printS->pop(printS);            \
                    printL->insertEnd(printL, printBT->elem);                  \
                } while (!printS->isEmpty(printS) &&                           \
                         ((BiTree_##elem_t)printS->top->elem)->right ==        \
                             printBT);                                         \
                printBT = NULL;                                                \
            }                                                                  \
        }                                                                      \
        elem_t *array = printL->toArray(printL);                               \
        printL->delete (printL);                                               \
        S->delete (S);                                                         \
        printS->delete (printS);                                               \
        return array;                                                          \
    }                                                                          \
    static BiTree_##elem_t BiTree_##elem_t##_init(elem_t arr[], ind_t len) {   \
        LQueue_pointer Q = LQueue_pointer_init();                              \
        int i = 0;                                                             \
        if (arr[i] == EMPTY || len < 1)                                        \
            return NULL;                                                       \
        BiTree_##elem_t BT =                                                   \
            (BiTree_##elem_t)malloc(sizeof(struct BiTreeNode_##elem_t));       \
        BT->elem = arr[i];                                                     \
        BT->left = BT->right = NULL;                                           \
        BT->travPre = BiTree_##elem_t##_travPre;                               \
        BT->travIn = BiTree_##elem_t##_travIn;                                 \
        BT->travPost = BiTree_##elem_t##_travPost;                             \
        Q->add(Q, (pointer)BT);                                                \
        i++;                                                                   \
        BiTree_##elem_t tempNode;                                              \
        while (!Q->isEmpty(Q)) {                                               \
            tempNode = (BiTree_##elem_t)Q->remove(Q);                          \
            if (i >= len)                                                      \
                break;                                                         \
            if (arr[i] != EMPTY) {                                             \
                tempNode->left = (BiTree_##elem_t)malloc(                      \
                    sizeof(struct BiTreeNode_##elem_t));                       \
                tempNode->left->elem = arr[i];                                 \
                tempNode->left->left = tempNode->left->right = NULL;           \
                tempNode->left->travPre = BiTree_##elem_t##_travPre;           \
                tempNode->left->travIn = BiTree_##elem_t##_travIn;             \
                tempNode->left->travPost = BiTree_##elem_t##_travPost;         \
                Q->add(Q, (pointer)tempNode->left);                            \
            }                                                                  \
            i++;                                                               \
            if (i >= len)                                                      \
                break;                                                         \
            if (arr[i] != EMPTY) {                                             \
                tempNode->right = (BiTree_##elem_t)malloc(                     \
                    sizeof(struct BiTreeNode_##elem_t));                       \
                tempNode->right->elem = arr[i];                                \
                tempNode->right->left = tempNode->right->right = NULL;         \
                tempNode->right->travPre = BiTree_##elem_t##_travPre;          \
                tempNode->right->travIn = BiTree_##elem_t##_travIn;            \
                tempNode->right->travPost = BiTree_##elem_t##_travPost;        \
                Q->add(Q, (pointer)tempNode->right);                           \
            }                                                                  \
            i++;                                                               \
        }                                                                      \
        Q->delete (Q);                                                         \
        return BT;                                                             \
    }
#endif