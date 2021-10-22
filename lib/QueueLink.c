#include "QueueLink.h"

LQueue CreateLQueue(Length MaxSize)
{
    LQueue Q = (LQueue) malloc(sizeof(struct ConLQueue));
    if(!Q)
        exit(EXIT_FAILURE);
    Q->Data = CreateLink();
    Q->Rear = Q->Data;
    Q->Volume = 0;
    return Q;
}

bool isEmptyLQ(LQueue Q)
{
    if(!Q->Data->next)
        return true;
    else return false;
}

bool AddLQ(LQueue Q, ETypeLQueue E)
{
    if(Insertpos(Q->Rear, E)) {
        Q->Rear = Locate(Q->Rear, 1);
        Q->Volume++;
        return true;
    } else 
        return false;
}

ETypeLQueue DeleteLQ(LQueue Q)
{
    if(isEmptyLQ(Q))
        return ERROR;
    ETypeLQueue element = Q->Data->elem;
    if(Deletepos(Q->Data)) {
        Q->Volume--;
        return element;
    } else 
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