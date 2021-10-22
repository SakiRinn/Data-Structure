#include "Stack.h"

Stack CreateStack(Length MaxSize)
{
    Stack S = (Stack) malloc(sizeof(struct ConStack));
    if(!S)
        exit(EXIT_FAILURE);
    S->Data = (ETypeStack*) malloc(MaxSize * sizeof(ETypeStack));
    if(!S->Data)
        exit(EXIT_FAILURE);
    S->Top = -1; 
    S->MaxSize = MaxSize;
    return S;
}

bool isFullS(Stack S)
{
    if(S->Top == S->MaxSize - 1)
        return true;
    else 
        return false;
}

bool isEmptyS(Stack S)
{
    if(S->Top == -1)
        return true;
    else 
        return false;
}

bool Push(Stack S, ETypeStack E)
{
    if(!isFullS(S)) {
        S->Top++;
        S->Data[S->Top] = E;
        return true;
    } else 
        return false;
}

ETypeStack Pop(Stack S)
{
    if(!isEmptyS(S)) {
        int elem = S->Data[S->Top];
        S->Top--;
        return elem;
    } else 
        return ERROR;
}