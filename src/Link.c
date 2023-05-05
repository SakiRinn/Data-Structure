#include "Link.h"
#include <stdio.h>
#include ".general.h"

Link Link_init() {
    Link self = (Link)malloc(sizeof(struct _Link));
    // attribute
    self->headNode = (LPos)malloc(sizeof(struct Node));
    if (!self->headNode)
        exit(EXIT_FAILURE);
    self->headNode->elem = (ElemType)HEAD_NODE;
    self->headNode->next = NULL;
    // method
    self->get       = Link_get;
    self->length    = Link_length;
    self->locate    = Link_locate;
    self->insertPos = Link_insertPos;
    self->insertInd = Link_insertInd;
    self->insertEnd = Link_insertEnd;
    self->removePos = Link_removePos;
    self->removeInd = Link_removeInd;
    self->delete    = Link_delete;
    self->print     = Link_print;
    return self;
}

LPos Link_locate(Link self, ind_t index) {
    LPos L = self->headNode;
    if (!L)
        return NULL;
    LPos ptr = L;
    for (int i = 0; i < index; i++) {
        if (!ptr->next)
            return NULL;
        else
            ptr = ptr->next;
    }
    return ptr;
}

bool Link_insertPos(LPos pre, ElemType E) {
    if (!pre)
        return false;
    LPos tmp = (LPos)malloc(sizeof(struct Node));
    if (!tmp)
        exit(EXIT_FAILURE);
    tmp->elem = E;
    tmp->next = pre->next;
    pre->next = tmp;
    return true;
}

bool Link_insertInd(Link self, ind_t index, ElemType E) {
    LPos L = self->headNode;
    if (!L || L->elem != (ElemType)HEAD_NODE)
        return false;
    LPos pre = self->locate(self, index);
    return self->insertPos(pre, E);
}

bool Link_insertEnd(Link self, ElemType E) {
    LPos L = self->headNode;
    if (!L || L->elem != (ElemType)HEAD_NODE)
        return false;
    LPos pre = L;
    while (pre->next)
        pre = pre->next;
    return self->insertPos(pre, E);
}

ElemType Link_removePos(LPos pre) {
    if (!pre || !pre->next)
        return (ElemType)ERROR;
    LPos tmp = pre->next;
    pre->next = tmp->next;
    ElemType value = tmp->elem;
    free(tmp);
    return value;
}

ElemType Link_removeInd(Link self, ind_t index) {
    LPos L = self->headNode;
    if (!L || L->elem != (ElemType)HEAD_NODE)
        return (ElemType)ERROR;
    if (!index)
        return (ElemType)ERROR;
    LPos pre = self->locate(self, index - 1);
    return self->removePos(pre);
}

ElemType Link_get(Link self, ind_t index) {
    LPos L = self->headNode;
    if (!L || L->elem != (ElemType)HEAD_NODE)
        return (ElemType)ERROR;
    LPos ptr = self->locate(self, index);
    if (!ptr)
        return (ElemType)ERROR;
    else
        return ptr->elem;
}

ind_t Link_length(Link self) {
    LPos L = self->headNode;
    if (!L || L->elem != (ElemType)HEAD_NODE)
        return (ElemType)ERROR;
    ind_t count = 0;
    LPos ptr = L;
    while (ptr->next) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void Link_delete(Link self) {
    LPos L = self->headNode;
    while (self->removePos(L) != (ElemType)ERROR)
        ;
    free(L);
    free(self);
}

void Link_print(Link self) {
    for (LPos L = self->headNode->next; L; L = L->next) {
        if (isFloat(L->elem))
            printf("%g ", (double)L->elem);
        else
            printf("%lld ", (long long)L->elem);
    }
    putchar('\n');
}
