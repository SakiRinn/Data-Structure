/*双向栈*/
#ifndef _STACK_DOUBLE_DIRECTION_H_
#define _STACK_DOUBLE_DIRECTION_H_
/* 说明：
使用一个数组实现的一对栈。
栈底分别位于两边，只要有空位就能进栈。 */
#include ".general.h"

/*Structure Declaration*/
typedef struct ConDStack *DStack;
struct ConDStack {
    ElemType *Data; 
    Cursor Top1; 
    Cursor Top2; 
    unsigned int MaxSize; 
};

/*Function Declaration*/
//创建一个双向栈
DStack CreateDStack(unsigned int MaxSize);
//进栈
bool DPush(DStack S, ElemType E, int tag);
//出栈
ElemType DPop(DStack S, int tag);

#endif