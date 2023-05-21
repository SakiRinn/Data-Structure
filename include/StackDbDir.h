/**
 * @file StackDbDir.h
 * @brief 双向栈
 *
 * 使用一个数组实现的一对栈.
 * 栈底分别位于两边, 只要有空位就能进栈.
 *
 * @attention 未测试!
 */
#ifndef _STACK_DOUBLE_DIRECTION_H_
#define _STACK_DOUBLE_DIRECTION_H_

#include ".general.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

// 两个栈的标记, 用于在push/pop时指定具体栈
typedef enum {
    S1, S2,
} StackTag;
typedef struct _DStack *DStack;
struct _DStack {
    // attribute
    ElemType *data;
    ind_t top1;
    ind_t top2;
    ind_t maxSize;
    // method
    bool        (*push)    (DStack, ElemType, StackTag);
    ElemType    (*pop)     (DStack, StackTag);
    void        (*delete)  (DStack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
DStack DStack_init(ind_t maxSize);
// 进栈
bool DStack_push(DStack self, ElemType E, StackTag tag);
// 出栈
ElemType DStack_pop(DStack self, StackTag tag);
// 销毁
void DStack_delete(DStack self);


#endif
