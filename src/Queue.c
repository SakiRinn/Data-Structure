#include "Queue.h"

Queue Queue_init(len_t maxSize) {
    Queue self;
    // attribute
    self.data = (ElemType *)malloc((maxSize + 1) * sizeof(ElemType));
    if (!self.data)
        exit(EXIT_FAILURE);
    self.front = -1;
    self.rear = -1;
    self.maxSize = maxSize;
    // method
    self.add        = Queue_add;
    self.remove     = Queue_remove;
    self.isFull     = Queue_isFull;
    self.isEmpty    = Queue_isEmpty;
    self.delete     = Queue_delete;
    return self;
}

bool Queue_isFull(Queue self) {
    return (self.rear + 1) % (self.maxSize) == self.front ? true : false;
}

bool Queue_isEmpty(Queue self) {
    return self.front == self.rear ? true : false;
}

bool Queue_add(Queue self, ElemType E) {
    if (Queue_isFull(self))
        return false;
    else {
        self.rear = (self.rear + 1) % self.maxSize;
        self.data[self.rear] = E;
        return true;
    }
}

ElemType Queue_remove(Queue self) {
    if (Queue_isEmpty(self))
        return ERROR;
    else {
        self.front = (self.front + 1) % self.maxSize;
        return self.data[self.front];
    }
}

void Queue_delete(Queue self) {
    free(self.data);
}
