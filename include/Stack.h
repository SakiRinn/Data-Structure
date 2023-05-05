/**
 * @file Stack.h
 * @brief 栈
 *
 */
#ifndef _STACK_H_
#define _STACK_H_

#include ".general.h"
#include "generic/Stack.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _Stack *Stack;
struct _Stack {
    // attribute
    ElemType *data;
    ind_t top;
    ind_t maxSize;
    // method
    bool        (*push)     (Stack, ElemType);
    ElemType    (*pop)      (Stack);
    bool        (*isFull)   (Stack);
    bool        (*isEmpty)  (Stack);
    void        (*delete)   (Stack);
    void        (*print)    (Stack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
Stack Stack_init(ind_t maxSize);
// 是否为满
bool Stack_isFull(Stack self);
// 是否为空
bool Stack_isEmpty(Stack self);
// 进栈
bool Stack_push(Stack self, ElemType E);
// 出栈: 成功, 返回出栈元素; 失败, 返回ERROR
ElemType Stack_pop(Stack self);
// 销毁
void Stack_delete(Stack self);
// 打印
void Stack_print(Stack self);


#endif
