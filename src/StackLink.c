#include "StackLink.h"

LStack LStack_init() {
    LStack self;
    // attribute
    self.data = Link_init();
    self.top = NULL;
    // method
    self.push       = LStack_push;
    self.pop        = LStack_pop;
    self.isEmpty    = LStack_isEmpty;
    self.length     = LStack_length;
    self.delete     = LStack_delete;
    return self;
}

bool LStack_isEmpty(LStack self) {
    return (self.data.head->elem == HEAD_NODE && !self.top) ? true : false;
}

bool LStack_push(LStack self, ElemType E) {
    if (self.data.insertPos(self.data.head, E)) {
        self.top = self.data.head->next;
        return true;
    } else
        return false;
}

ElemType LStack_pop(LStack self) {
    if (self.isEmpty(self))
        return ERROR;
    ElemType elem = self.top->elem;
    self.top = self.top->next;
    return self.data.removePos(self.data.head) ? elem : ERROR;
}

bool LStack_delete(LStack self) {
    return self.data.delete(self.data) ? true : false;
}

len_t LStack_length(LStack self) {
    return self.data.length(self.data);
}
