#include "QueueLink.h"

LQueue LQueue_init()
{
    LQueue Q = (LQueue) malloc(sizeof(struct _LQueue));
    if (!Q)
        exit(EXIT_FAILURE);
    Q->data = Link_init();
    Q->rear = Q->data;
    return Q;
}

bool LQueue_isEmpty(LQueue Q)
{
    return !(Q->data->next) ? true : false;
}

bool LQueue_add(LQueue Q, ElemType E)
{
    if (Link_insertEnd(Q->data, E))
    {
        Q->rear = Link_locate(Q->rear, 1);
        return true;
    }
    else
        return false;
}

ElemType LQueue_delete(LQueue Q)
{
    if (LQueue_isEmpty(Q))
        return ERROR;
    ElemType elem = Q->data->next->elem;
    if (Link_deletePos(Q->data))
        return elem;
    else
        return ERROR;
}

bool LQueue_remove(LQueue Q)
{
    if (Link_remove(Q->data))
    {
        free(Q);
        return true;
    }
    else
        return false;
}

len_t LQueue_len(LQueue Q)
{
    return Link_len(Q->data);
}