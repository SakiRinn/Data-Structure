#include "QueueLink.h"

LQueue LQueue_init() {
    LQueue self;

    // attribute
    self.data = Link_init();
    self.rear = self.data.head;

    // method
    self.add        = LQueue_add;
    self.remove     = LQueue_remove;
    self.isEmpty    = LQueue_isEmpty;
    self.length     = LQueue_length;
    self.delete     = LQueue_delete;

    return self;
}

bool LQueue_isEmpty(LQueue self) {
    return !(self.data.head->next) ? true : false;
}

bool LQueue_add(LQueue self, ElemType E) {
    if (self.data.insertEnd(self.data, E)) {
        self.rear = self.rear->next;
        return true;
    } else
        return false;
}

ElemType LQueue_remove(LQueue self) {
    if (self.isEmpty(self))
        return ERROR;
    ElemType elem = self.data.head->next->elem;
    if (self.data.removePos(self.data.head))
        return elem;
    else
        return ERROR;
}

bool LQueue_delete(LQueue self) {
    return self.data.delete(self.data) ? true : false;
}

len_t LQueue_length(LQueue self) {
    return self.data.length(self.data);
}