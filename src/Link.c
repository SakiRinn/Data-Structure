#include "Link.h"

Link Link_init() {
    Link L = (Link)malloc(sizeof(struct Node));
    if (!L)
        exit(EXIT_FAILURE);
    L->elem = HEAD_NODE;
    L->next = NULL;
    return L;
}

LoopLink LoopLink_init(ElemType E) {
    Link L = Link_init();
    Link_insertPos(L, E);
    L->next->next = L;
    return L;
}

Pos Link_locate(Link L, ind_t subs) {
    if (!L)
        return NULL;
    Pos ptr = L;
    for (int i = 0; i < subs; i++) {
        if (!ptr->next)
            return NULL;
        else
            ptr = ptr->next;
    }
    return ptr;
}

bool Link_insertPos(Pos pre, ElemType E) {
    if (!pre)
        return false;
    Pos tmp = (Pos)malloc(sizeof(struct Node));
    if (!tmp)
        exit(EXIT_FAILURE);
    tmp->elem = E;
    tmp->next = pre->next;
    pre->next = tmp;
    return true;
}

bool Link_insertInd(Link L, ind_t subs, ElemType E) {
    if (!L || L->elem != HEAD_NODE)
        return false;
    Pos pre = Link_locate(L, subs);
    return Link_insertPos(pre, E);
}

bool Link_insertEnd(Link L, ElemType E) {
    if (!L || L->elem != HEAD_NODE)
        return false;
    Pos pre = L;
    while (pre->next)
        pre = pre->next;
    return Link_insertPos(pre, E);
}

bool Link_deletePos(Pos pre) {
    if (!pre || !pre->next)
        return false;
    Pos tmp = pre->next;
    pre->next = tmp->next;
    free(tmp);
    return true;
}

bool Link_deleteInd(Link L, ind_t subs) {
    if (!L || L->elem != HEAD_NODE)
        return false;
    if (!subs)
        return false;
    Pos pre = Link_locate(L, subs - 1);
    return Link_deletePos(pre);
}

ElemType Link_search(Link L, ind_t subs) {
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    Pos ptr = Link_locate(L, subs);
    if (!ptr)
        return ERROR;
    else
        return ptr->elem;
}

len_t Link_len(Link L) {
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    len_t count = 0;
    Pos ptr = L;
    while (ptr->next) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

bool Link_remove(Link L) {
    if (!L || L->elem != HEAD_NODE)
        return false;
    while (Link_deletePos(L))
        ;
    free(L);
    return true;
}
