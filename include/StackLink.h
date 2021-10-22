/*栈(链)*/
#ifndef _STACK_LINK_H_
#define _STACK_LINK_H_
/* 说明：
链栈的栈顶指针就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"
typedef long ETypeLStack;

/*Structure Declaration*/
typedef struct ConLStack *LStack;
struct ConLStack {
    Link Data;
    Pos Top;
};

/*Function Declaration*/
//创建一个栈(链)
LStack CreateLStack();
//栈(链)是否为空
bool isEmptyLS(LStack S);
//进栈(链)
bool LPush(LStack S, ETypeLStack E);
//出栈(链)
ETypeLStack LPop(LStack S);
//销毁链栈
bool RemoveLStack(LStack S);
//返回链栈长度
Length LStackLen(LStack S);

#endif