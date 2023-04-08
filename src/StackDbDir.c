#include "StackDbDir.h"
#include ".general.h"

DStack DStack_init(len_t maxSize)
{
    DStack S = (DStack) malloc(sizeof(struct ConDStack));
    S->data = (ElemType*) malloc(maxSize * sizeof(ElemType));
    S->top1 = -1;
    S->top2 = maxSize;
    S->maxSize = maxSize;
    return S;
}

bool DStack_push(DStack S, ElemType E, int tag)
{
    //双向栈满
    if(S->top1 == S->top2)
        return false;
    //Push其中一个栈
    if (tag == 1) {
        S->top1++;
        S->data[S->top1] = E;
        return true;
    } else if (tag == 2) {
        S->top2--;
        S->data[S->top2] = E;
        return true;
    } else
        return false;
}

ElemType DStack_pop(DStack S, int tag)
{
    //双向栈空
    if(S->top1 == -1 || S->top2 == S->maxSize)
        return ERROR;
    //Pop其中一个栈
    if(tag == 1) {
        ElemType re = S->data[S->top1];
        S->top1--;
        return re;
    } else if(tag == 2) {
        ElemType re = S->data[S->top2];
        S->top2++;
        return re;
    } else
        return ERROR;
}