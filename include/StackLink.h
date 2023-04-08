/*栈(链)*/
#ifndef _STACK_LINK_H_
#define _STACK_LINK_H_
/* 说明：
链栈的栈顶指针就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"

/*Structure Declaration*/
typedef struct _LStack *LStack;
struct _LStack {
    Link data;
    Pos top;
};

/*Function Declaration*/
//创建一个栈(链)
LStack LStack_init();
//栈(链)是否为空
bool LStack_isEmpty(LStack S);
//进栈(链)
bool LStack_push(LStack S, ElemType E);
//出栈(链)
ElemType LStack_pop(LStack S);
//销毁链栈
bool LStack_remove(LStack S);
//返回链栈长度
len_t LStack_len(LStack S);

#endif
