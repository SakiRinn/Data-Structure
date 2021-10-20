#include "StackDbDir.h"

DStack CreateDStack(unsigned int MaxSize)
{
    DStack S = (DStack) malloc(sizeof(struct ConDStack));
    S->Data = (ElemType*) malloc(MaxSize*sizeof(ElemType));
    S->Top1 = -1;
    S->Top2 = MaxSize;
    S->MaxSize = MaxSize;
    return S;
}

bool DPush(DStack S, ElemType E, int tag)
{
    //双向栈满
    if(S->Top1 == S->Top2)
        return false;
    //Push其中一个栈
    if(tag == 1) {
        S->Top1++;
        S->Data[S->Top1] = E;
        return true;
    } else if(tag == 2) {
        S->Top2--;
        S->Data[S->Top2] = E;
        return true;
    } else 
        return false;
}

ElemType DPop(DStack S, int tag)
{
    //双向栈空
    if(S->Top1 == -1 || S->Top2 == S->MaxSize)
        return ERROR;
    //Pop其中一个栈
    if(tag == 1) {
        int re = S->Data[S->Top1];
        S->Top1--;
        return re;
    } else if(tag == 2) {
        int re = S->Data[S->Top2];
        S->Top2++;
        return re;
    } else 
        return ERROR;
}