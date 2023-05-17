/**
 * @file StackLink.h
 * @brief 链栈
 *
 * 头结点作为栈的顶部, 栈顶指针就是链表头结点的指针.
 */
#ifndef _STACK_LINK_H_
#define _STACK_LINK_H_

#include ".general.h"
#include "Link.h"
#include "generic/StackLink.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _LStack *LStack;
struct _LStack {
    // attribute
    Link data;
    LPos top;
    // method
    bool        (*push)     (LStack, ElemType);
    ElemType    (*pop)      (LStack);
    bool        (*isEmpty)  (LStack);
    ind_t       (*length)   (LStack);
    void        (*delete)   (LStack);
    void        (*print)    (LStack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
LStack LStack_init();
// 是否为空
bool LStack_isEmpty(LStack self);
// 进栈
bool LStack_push(LStack self, ElemType E);
// 出栈
ElemType LStack_pop(LStack self);
// 销毁
void LStack_delete(LStack self);
// 返回长度
ind_t LStack_length(LStack self);
// 打印
void LStack_print(LStack self);


#endif
