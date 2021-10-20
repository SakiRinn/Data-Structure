#include "Queue.h"

Queue CreateQueue(Length MaxSize)
{
    Queue Q = (Queue) malloc(sizeof(struct ConQueue));
    if(!Q)
        exit(EXIT_FAILURE);
    Q->Data = (ElemType*) malloc((MaxSize+1) * sizeof(ElemType));
    if(!Q->Data)
        exit(EXIT_FAILURE);
    Q->Front = -1;
    Q->Rear = -1;
    Q->MaxSize = MaxSize;
    return Q;
}

bool isFullQ(Queue Q)
{
    if((Q->Rear + 1) % (Q->MaxSize) == Q->Front) 
        return true;
    else 
        return false;
}

bool isEmptyQ(Queue Q)
{
    if(Q->Front == Q->Rear)
        return true;
    else 
        return false;
}

bool AddQ(Queue Q, ElemType E)
{
    if(isFullQ(Q))
        return false;
    else {
        Q->Rear = (Q->Rear + 1) % Q->MaxSize;
        Q->Data[Q->Rear] = E;
        return true;
    }
}

ElemType DeleteQ(Queue Q)
{
    if(isEmptyQ(Q)) 
        return ERROR;
    else {
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}