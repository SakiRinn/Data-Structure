/*栈*/
#ifndef _STACK_H_
#define _STACK_H_

#include ".general.h"
typedef int ETypeStack;

/*Structure Declaration*/
typedef struct ConStack *Stack;
struct ConStack {
    ETypeStack *Data; 
    Cursor Top; 
    Length MaxSize; 
};

/*Function Declaration*/
//创建一个栈
Stack CreateStack(Length MaxSize);
//栈是否为满
bool isFullS(Stack S);
//栈是否为空
bool isEmptyS(Stack S);
//进栈
bool Push(Stack S, ETypeStack E);
//出栈：成功，返回出栈元素；失败，返回ERROR
ETypeStack Pop(Stack S);

#endif