#include "StackLink.h"

LStack LStack_init() {
    LStack S = (LStack)malloc(sizeof(LStack));
    if (!S)
        exit(EXIT_FAILURE);
    S->data = Link_init();
    S->top = NULL;
    return S;
}

bool LStack_isEmpty(LStack S) {
    return (S->data->elem == HEAD_NODE && !S->top) ? true : false;
}

bool LStack_push(LStack S, ElemType E) {
    if (Link_insertPos(S->data, E)) {
        S->top = Link_locate(S->data, 1);
        return true;
    } else
        return false;
}

ElemType LStack_pop(LStack S) {
    if (LStack_isEmpty(S))
        return ERROR;
    ElemType elem = S->top->elem;
    S->top = Link_locate(S->top, 1);
    if (Link_deletePos(S->data))
        return elem;
    else
        return ERROR;
}

bool LStack_remove(LStack S) {
    if (Link_remove(S->data)) {
        free(S);
        return true;
    } else
        return false;
}

len_t LStack_len(LStack S) {
    return Link_len(S->data);
}