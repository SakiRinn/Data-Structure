#include "Queue.h"
#include ".general.h"

Queue Queue_init(ind_t maxSize) {
    Queue self = (Queue)malloc(sizeof(struct _Queue));
    // attribute
    self->data = (ElemType *)malloc((maxSize + 1) * sizeof(ElemType));
    if (!self->data)
        exit(EXIT_FAILURE);
    self->front = 0;
    self->rear = 0;
    self->maxSize = maxSize;
    // method
    self->add       = Queue_add;
    self->remove    = Queue_remove;
    self->isFull    = Queue_isFull;
    self->isEmpty   = Queue_isEmpty;
    self->delete    = Queue_delete;
    self->print     = Queue_print;
    return self;
}

bool Queue_isFull(Queue self) {
    return (self->rear + 1) % (self->maxSize + 1) == self->front ? \
        true : false;
}

bool Queue_isEmpty(Queue self) {
    return (self->front + 1) % (self->maxSize + 1) == self->rear ? \
        true : false;
}

bool Queue_add(Queue self, ElemType E) {
    if (self->isFull(self))
        return false;
    else {
        self->data[self->rear] = E;
        self->rear = (self->rear + 1) % (self->maxSize + 1);
        return true;
    }
}

ElemType Queue_remove(Queue self) {
    if (self->isEmpty(self))
        return (ElemType)ERROR;
    else {
        ElemType value = self->data[self->front];
        self->front = (self->front + 1) % (self->maxSize + 1);
        return value;
    }
}

void Queue_delete(Queue self) {
    free(self->data);
    free(self);
}

void Queue_print(Queue self) {
    for (ind_t i = self->front; i != self->rear;
         i = (i + 1) % (self->maxSize + 1)) {
        if (isFloat(self->data[i]))
            printf("%g ", (double)self->data[i]);
        else
            printf("%lld ", (long long)self->data[i]);
    }
    putchar('\n');
}
