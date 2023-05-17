/**
 * @file Queue.h
 * @brief 队列
 *
 * front和rear间的元素为存储的元素.
 * 该方法可以有效地减少操作量, 无需每次增删元素都`realloc()`.
 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include ".general.h"
#include "generic/Queue.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct _Queue *Queue;
struct _Queue {
    // attribute
    ElemType *data;
    ind_t front;
    ind_t rear;
    ind_t maxSize;
    // method
    bool        (*add)      (Queue, ElemType);
    ElemType    (*remove)   (Queue);
    bool        (*isFull)   (Queue);
    bool        (*isEmpty)  (Queue);
    void        (*delete)   (Queue);
    void        (*print)    (Queue);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
Queue Queue_init(ind_t maxSize);
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
// 打印
void Queue_print(Queue self);


#endif
