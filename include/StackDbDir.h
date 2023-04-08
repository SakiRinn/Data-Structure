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
    ElemType *data;
    ind_t top1;
    ind_t top2;
    len_t maxSize;
};

/*Function Declaration*/
//创建一个双向栈
DStack DStack_init(len_t maxSize);
//进栈
bool DStack_push(DStack S, ElemType E, int tag);
//出栈
ElemType DStack_pop(DStack S, int tag);

#endif
