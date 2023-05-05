#include "StackLink.h"

LStack LStack_init() {
    LStack self = (LStack)malloc(sizeof(struct _LStack));
    // attribute
    self->data = Link_init();
    self->top = NULL;
    // method
    self->push       = LStack_push;
    self->pop        = LStack_pop;
    self->isEmpty    = LStack_isEmpty;
    self->length     = LStack_length;
    self->delete     = LStack_delete;
    self->print      = LStack_print;
    return self;
}

bool LStack_isEmpty(LStack self) {
    return (self->data->headNode->elem == (ElemType)HEAD_NODE \
        && !self->top) ? true : false;
}

bool LStack_push(LStack self, ElemType E) {
    if (self->data->insertPos(self->data->headNode, E)) {
        self->top = self->data->headNode->next;
        return true;
    } else
        return false;
}

ElemType LStack_pop(LStack self) {
    if (self->isEmpty(self))
        return (ElemType)ERROR;
    ElemType elem = self->top->elem;
    self->top = self->top->next;
    return self->data->removePos(self->data->headNode) ? \
        elem : (ElemType)ERROR;
}

void LStack_delete(LStack self) {
    return self->data->delete(self->data);
}

ind_t LStack_length(LStack self) {
    return self->data->length(self->data);
}

void LStack_print(LStack self) {
    printf("[Warning] Print in reverse order.\n");
    self->data->print(self->data);
}
