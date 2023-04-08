/*队列*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include ".general.h"

/*Structure Declaration*/
typedef struct _Queue *Queue;
struct _Queue {
    ElemType *data;
    ind_t front;
    ind_t rear;
    len_t maxSize;
};

/*Function Declaration*/
//创建一个队列
Queue Queue_init(len_t maxSize);
//队列是否为满
bool Queue_isFull(Queue Q);
//队列是否为空
bool Queue_isEmpty(Queue Q);
//添加
bool Queue_add(Queue Q, ElemType E);
//删除：成功，返回被删除元素值；失败，返回ERROR
ElemType Queue_delete(Queue Q);

#endif
