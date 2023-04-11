/*队列(链)*/
#ifndef _QUEUE_LINK_H_
#define _QUEUE_LINK_H_

/* 说明：
链队列的前指针Front就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"
#include "generic/QueueLink.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------
typedef struct _LQueue LQueue;
struct _LQueue {
    // attribute
    Link data;
    LPos rear;
    // method
    bool        (*add)      (LQueue, ElemType);
    ElemType    (*remove)   (LQueue);
    bool        (*isEmpty)  (LQueue);
    len_t       (*length)   (LQueue);
    bool        (*delete)   (LQueue);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 创建一个队列(链)
LQueue LQueue_init();
// 队列(链)是否为空
bool LQueue_isEmpty(LQueue self);
// 添加(链)
bool LQueue_add(LQueue self, ElemType E);
// 删除(链)
ElemType LQueue_remove(LQueue self);
// 销毁链队列
bool LQueue_delete(LQueue self);
// 返回链队列长度
len_t LQueue_length(LQueue self);


#endif
