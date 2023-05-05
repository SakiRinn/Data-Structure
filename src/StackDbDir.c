#include "StackDbDir.h"

DStack DStack_init(ind_t maxSize) {
    DStack self = (DStack)malloc(sizeof(struct _DStack));
    // attribute
    self->data = (ElemType *)malloc(maxSize * sizeof(ElemType));
    self->top1 = -1;
    self->top2 = maxSize;
    self->maxSize = maxSize;
    // method
    self->push   = DStack_push;
    self->pop    = DStack_pop;
    self->delete = DStack_delete;
    return self;
}

bool DStack_push(DStack self, ElemType E, StackTag tag) {
    // 双向栈满
    if (self->top1 == self->top2)
        return false;
    // Push其中一个栈
    if (tag == S1) {
        self->top1++;
        self->data[self->top1] = E;
        return true;
    } else if (tag == S2) {
        self->top2--;
        self->data[self->top2] = E;
        return true;
    } else
        return false;
}

ElemType DStack_pop(DStack self, StackTag tag) {
    // 双向栈空
    if (self->top1 == -1 || self->top2 == self->maxSize)
        return (ElemType)ERROR;
    // Pop其中一个栈
    if (tag == S1) {
        ElemType re = self->data[self->top1];
        self->top1--;
        return re;
    } else if (tag == S2) {
        ElemType re = self->data[self->top2];
        self->top2++;
        return re;
    } else
        return (ElemType)ERROR;
}

void DStack_delete(DStack self) {
    free(self->data);
    free(self);
}
