#include "QueueLink.h"

LQueue CreateLQueue()
{
    LQueue Q = (LQueue) malloc(sizeof(struct ConLQueue));
    if (!Q)
        exit(EXIT_FAILURE);
    Q->Data = CreateLink();
    Q->Rear = Q->Data;
    return Q;
}

bool isEmptyLQ(LQueue Q)
{
    if (!Q->Data->next)
        return true;
    else
        return false;
}

bool AddLQ(LQueue Q, ETypeLQueue E)
{
    if (Insertend(Q->Data, E))
    {
        Q->Rear = Locate(Q->Rear, 1);
        return true;
    }
    else 
        return false;
}

ETypeLQueue DeleteLQ(LQueue Q)
{
    if (isEmptyLQ(Q))
        return ERROR;
    ETypeLQueue elem = Q->Data->next->elem;
    if (Deletepos(Q->Data))
        return elem;
    else
        return ERROR;
}

bool RemoveLQ(LQueue Q)
{
    if (RemoveLink(Q->Data))
    {
        free(Q);
        return true;
    }
    else
        return false;
}

Length LQueueLen(LQueue Q)
{
    return LinkLen(Q->Data);
}