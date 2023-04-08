/*栈*/
#ifndef _STACK_H_
#define _STACK_H_

#include ".general.h"

/*Structure Declaration*/
typedef struct _Stack *Stack;
struct _Stack {
    ElemType *data;
    ind_t top;
    len_t maxSize;
};

/*Function Declaration*/
//创建一个栈
Stack Stack_init(len_t maxSize);
//栈是否为满
bool Stack_isFull(Stack S);
//栈是否为空
bool Stack_isEmpty(Stack S);
//进栈
bool Stack_push(Stack S, ElemType E);
//出栈：成功，返回出栈元素；失败，返回ERROR
ElemType Stack_pop(Stack S);

#endif
