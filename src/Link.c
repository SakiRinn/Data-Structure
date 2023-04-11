#include "Link.h"

Link Link_init() {
    Link self;
    // attribute
    self.head = (LPos)malloc(sizeof(struct Node));
    if (!self.head)
        exit(EXIT_FAILURE);
    self.head->elem = HEAD_NODE;
    self.head->next = NULL;
    // method
    self.get       = Link_get;
    self.length    = Link_length;
    self.locate    = Link_locate;
    self.insertPos = Link_insertPos;
    self.insertInd = Link_insertInd;
    self.insertEnd = Link_insertEnd;
    self.removePos = Link_removePos;
    self.removeInd = Link_removeInd;
    self.delete    = Link_delete;
    return self;
}

LPos Link_locate(Link self, ind_t subs) {
    LPos L = self.head;
    if (!L)
        return NULL;
    LPos ptr = L;
    for (int i = 0; i < subs; i++) {
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

bool Link_insertInd(Link self, ind_t subs, ElemType E) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return false;
    LPos pre = self.locate(self, subs);
    return self.insertPos(pre, E);
}

bool Link_insertEnd(Link self, ElemType E) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return false;
    LPos pre = L;
    while (pre->next)
        pre = pre->next;
    return self.insertPos(pre, E);
}

bool Link_removePos(LPos pre) {
    if (!pre || !pre->next)
        return false;
    LPos tmp = pre->next;
    pre->next = tmp->next;
    free(tmp);
    return true;
}

bool Link_removeInd(Link self, ind_t subs) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return false;
    if (!subs)
        return false;
    LPos pre = self.locate(self, subs - 1);
    return self.removePos(pre);
}

ElemType Link_get(Link self, ind_t subs) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    LPos ptr = self.locate(self, subs);
    if (!ptr)
        return ERROR;
    else
        return ptr->elem;
}

len_t Link_length(Link self) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    len_t count = 0;
    LPos ptr = L;
    while (ptr->next) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

bool Link_delete(Link self) {
    LPos L = self.head;
    if (!L || L->elem != HEAD_NODE)
        return false;
    while (self.removePos(L))
        ;
    free(L);
    return true;
}
