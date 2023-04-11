/*双向栈*/
#ifndef _STACK_DOUBLE_DIRECTION_H_
#define _STACK_DOUBLE_DIRECTION_H_

/* 说明：
使用一个数组实现的一对栈。
栈底分别位于两边，只要有空位就能进栈。 */
#include ".general.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _DStack DStack;
typedef enum {
    S1, S2,
} StackTag;
struct _DStack {
    // attribute
    ElemType *data;
    ind_t top1;
    ind_t top2;
    len_t maxSize;
    // method
    bool        (*push)    (DStack, ElemType, StackTag);
    ElemType    (*pop)     (DStack, StackTag);
    void        (*delete)  (DStack);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
DStack DStack_init(len_t maxSize);
// 进栈
bool DStack_push(DStack self, ElemType E, StackTag tag);
// 出栈
ElemType DStack_pop(DStack self, StackTag tag);
// 销毁
void DStack_delete(DStack self);


#endif
