#include "QueueLink.h"

LQueue LQueue_init() {
    LQueue self = (LQueue)malloc(sizeof(struct _LQueue));
    // attribute
    self->data = Link_init();
    self->rear = self->data->headNode;
    // method
    self->add       = LQueue_add;
    self->remove    = LQueue_remove;
    self->isEmpty   = LQueue_isEmpty;
    self->length    = LQueue_length;
    self->delete    = LQueue_delete;
    self->print     = LQueue_print;
    return self;
}

bool LQueue_isEmpty(LQueue self) {
    return !(self->data->headNode->next) ? true : false;
}

bool LQueue_add(LQueue self, ElemType E) {
    if (self->data->insertEnd(self->data, E)) {
        self->rear = self->rear->next;
        return true;
    } else
        return false;
}

ElemType LQueue_remove(LQueue self) {
    if (self->isEmpty(self))
        return (ElemType)ERROR;
    ElemType elem = self->data->headNode->next->elem;
    if (self->data->length(self->data) == 1)
        self->rear = self->data->headNode;
    if (self->data->removePos(self->data->headNode))
        return elem;
    else
        return (ElemType)ERROR;
}

void LQueue_delete(LQueue self) {
    self->data->delete(self->data);
    free(self);
}

ind_t LQueue_length(LQueue self) {
    return self->data->length(self->data);
}

void LQueue_print(LQueue self) {
    self->data->print(self->data);
}
