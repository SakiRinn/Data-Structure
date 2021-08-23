#include "QueueLink.h"

LQueue CreateLQueue(unsigned int MaxSize)
{
    LQueue Q = (LQueue) malloc(sizeof(struct ConLQueue));
    if(!Q)
        exit(EXIT_FAILURE);
    Q->Data = CreateLink();
    Q->Rear = Q->Data;
    Q->Volume = 0;
    return Q;
}

bool IsEmptyLQ(LQueue Q)
{
    if(!Q->Data->next)
        return true;
    else return false;
}

bool AddLQ(LQueue Q, ElemType E)
{
    if(Insertpos(Q->Rear, E)) {
        Q->Rear = Locate(Q->Rear, 1);
        Q->Volume++;
        return true;
    } else 
        return false;
}

ElemType DeleteLQ(LQueue Q)
{
    if(IsEmptyLQ(Q))
        return ERROR;
    ElemType element = Q->Data->elem;
    if(Deletepos(Q->Data)) {
        Q->Volume--;
        return element;
    } else 
        return ERROR;
}