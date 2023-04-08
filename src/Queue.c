#include "Queue.h"
#include ".general.h"

Queue Queue_init(len_t maxSize) {
    Queue Q = (Queue)malloc(sizeof(Queue));
    if (!Q)
        exit(EXIT_FAILURE);
    Q->data = (ElemType *)malloc((maxSize + 1) * sizeof(ElemType));
    if (!Q->data)
        exit(EXIT_FAILURE);
    Q->front = -1;
    Q->rear = -1;
    Q->maxSize = maxSize;
    return Q;
}

bool Queue_isFull(Queue Q) {
    return (Q->rear + 1) % (Q->maxSize) == Q->front ? true : false;
}

bool Queue_isEmpty(Queue Q) { return Q->front == Q->rear ? true : false; }

bool Queue_add(Queue Q, ElemType E) {
    if (Queue_isFull(Q))
        return false;
    else {
        Q->rear = (Q->rear + 1) % Q->maxSize;
        Q->data[Q->rear] = E;
        return true;
    }
}

ElemType Queue_delete(Queue Q) {
    if (Queue_isEmpty(Q))
        return ERROR;
    else {
        Q->front = (Q->front + 1) % Q->maxSize;
        return Q->data[Q->front];
    }
}