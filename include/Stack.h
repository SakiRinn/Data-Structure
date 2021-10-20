/*栈*/
#ifndef _STACK_H_
#define _STACK_H_

#include ".general.h"

/*Structure Declaration*/
typedef struct ConStack *Stack;
struct ConStack {
    ElemType *Data; 
    Cursor Top; 
    unsigned int MaxSize; 
};

/*Function Declaration*/
//创建一个栈
Stack CreateStack(unsigned int MaxSize);
//栈是否为满
bool IsFullS(Stack S);
//栈是否为空
bool IsEmptyS(Stack S);
//进栈
bool Push(Stack S, ElemType E);
//出栈：成功，返回出栈元素；失败，返回ERROR
ElemType Pop(Stack S);

#endif