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

// 初始化
LQueue LQueue_init();
// 是否为空
bool LQueue_isEmpty(LQueue self);
// 添加
bool LQueue_add(LQueue self, ElemType E);
// 删除: 成功, 返回被删除元素值; 失败, 返回ERROR
ElemType LQueue_remove(LQueue self);
// 销毁
bool LQueue_delete(LQueue self);
// 返回长度
len_t LQueue_length(LQueue self);


#endif
