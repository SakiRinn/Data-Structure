/*栈*/
#ifndef _STACK_H_
#define _STACK_H_

#include ".general.h"
#include "generic/Stack.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _Stack Stack;
struct _Stack {
    // attribute
    ElemType *data;
    ind_t top;
    len_t maxSize;
    // method
    bool        (*push)     (Stack, ElemType);
    ElemType    (*pop)      (Stack);
    bool        (*isFull)   (Stack);
    bool        (*isEmpty)  (Stack);
    void        (*delete)   (Stack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 创建一个栈
Stack Stack_init(len_t maxSize);
// 栈是否为满
bool Stack_isFull(Stack self);
// 栈是否为空
bool Stack_isEmpty(Stack self);
// 进栈
bool Stack_push(Stack self, ElemType E);
// 出栈：成功，返回出栈元素；失败，返回ERROR
ElemType Stack_pop(Stack self);
// 删除
void Stack_delete(Stack self);


#endif
