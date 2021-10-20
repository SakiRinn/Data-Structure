#include "StackLink.h"

LStack CreateLStack(void)
{
    LStack S = (LStack) malloc(sizeof(struct ConLStack));
    if(!S)
        exit(EXIT_FAILURE);
    S->Data = CreateLink();
    S->Top = NULL;
    S->Volume = 0;
    return S;
}

bool IsEmptyLS(LStack S)
{
    if(!S->Data->next)
        return true;
    else 
        return false;
}


bool LPush(LStack S, ElemType E)
{
    if(Insertpos(S->Data, E)) {
        S->Top = Locate(S->Data, 1);
        S->Volume++;
        return true;
    } else 
        return false;
}

ElemType LPop(LStack S)
{
    if(IsEmptyLS(S))
        return ERROR;
    ElemType element = S->Top->elem;
    S->Top = Locate(S->Top, 1);
    if(Deletepos(S->Data)) {
        S->Volume--;
        return element;
    } else 
        return ERROR;
}