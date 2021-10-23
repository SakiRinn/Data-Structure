#include "StackLink.h"

LStack CreateLStack()
{
    LStack S = (LStack)malloc(sizeof(struct ConLStack));
    if (!S)
        exit(EXIT_FAILURE);
    S->Data = CreateLink();
    S->Top = NULL;
    return S;
}

bool isEmptyLS(LStack S)
{
    if (S->Data->elem == HEAD_NODE && !S->Top)
        return true;
    else
        return false;
}

bool LPush(LStack S, ETypeLStack E)
{
    if (Insertpos(S->Data, E))
    {
        S->Top = Locate(S->Data, 1);
        return true;
    }
    else
        return false;
}

ETypeLStack LPop(LStack S)
{
    if (isEmptyLS(S))
        return ERROR;
    ETypeLStack elem = S->Top->elem;
    S->Top = Locate(S->Top, 1);
    if (Deletepos(S->Data))
        return elem;
    else
        return ERROR;
}

bool RemoveLStack(LStack S)
{
    if (RemoveLink(S->Data))
    {
        free(S);
        return true;
    }
    else
        return false;
}

Length LStackLen(LStack S)
{
    return LinkLen(S->Data);
}