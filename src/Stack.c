#include "Stack.h"

Stack Stack_init(len_t maxSize) {
    Stack self;
    // attribute
    self.data = (ElemType *)malloc(maxSize * sizeof(ElemType));
    if (!self.data)
        exit(EXIT_FAILURE);
    self.top = -1;
    self.maxSize = maxSize;
    // method
    self.push       = Stack_push;
    self.pop        = Stack_pop;
    self.isFull     = Stack_isFull;
    self.isEmpty    = Stack_isEmpty;
    return self;
}

bool Stack_isFull(Stack self) {
    return self.top == self.maxSize - 1 ? true : false;
}

bool Stack_isEmpty(Stack self) {
    return self.top == -1 ? true : false;
}

bool Stack_push(Stack self, ElemType E) {
    if (!self.isFull(self)) {
        self.top++;
        self.data[self.top] = E;
        return true;
    } else
        return false;
}

ElemType Stack_pop(Stack self) {
    if (!self.isEmpty(self)) {
        ElemType elem = self.data[self.top];
        self.top--;
        return elem;
    } else
        return ERROR;
}

void Stack_delete(Stack self) {
    free(self.data);
}
