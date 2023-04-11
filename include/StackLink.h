/*栈(链)*/
#ifndef _STACK_LINK_H_
#define _STACK_LINK_H_

/* 说明：
链栈的栈顶指针就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"
#include "generic/StackLink.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _LStack LStack;
struct _LStack {
    // attribute
    Link data;
    LPos top;
    // method
    bool        (*push)     (LStack, ElemType);
    ElemType    (*pop)      (LStack);
    bool        (*isEmpty)  (LStack);
    len_t       (*length)   (LStack);
    bool        (*delete)   (LStack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 创建一个栈(链)
LStack LStack_init();
// 栈(链)是否为空
bool LStack_isEmpty(LStack self);
// 进栈(链)
bool LStack_push(LStack self, ElemType E);
// 出栈(链)
ElemType LStack_pop(LStack self);
// 销毁链栈
bool LStack_delete(LStack self);
// 返回链栈长度
len_t LStack_length(LStack self);


#endif
