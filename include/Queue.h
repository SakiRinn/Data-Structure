/*队列*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include ".general.h"
#include "generic/Queue.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _Queue Queue;
struct _Queue {
    // attribute
    ElemType *data;
    ind_t front;
    ind_t rear;
    len_t maxSize;
    // method
    bool        (*add)      (Queue, ElemType);
    ElemType    (*remove)   (Queue);
    bool        (*isFull)   (Queue);
    bool        (*isEmpty)  (Queue);
    void        (*delete)   (Queue);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
Queue Queue_init(len_t maxSize);
// 是否为满
bool Queue_isFull(Queue self);
// 是否为空
bool Queue_isEmpty(Queue self);
// 添加
bool Queue_add(Queue self, ElemType E);
// 删除: 成功, 返回被删除元素值; 失败, 返回ERROR
ElemType Queue_remove(Queue self);
// 销毁
void Queue_delete(Queue self);


#endif
