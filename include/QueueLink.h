/*队列(链)*/
#ifndef _QUEUE_LINK_H_
#define _QUEUE_LINK_H_
/* 说明：
链队列的前指针Front就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"

/*Structure Declaration*/
typedef struct ConLQueue *LQueue;
struct ConLQueue {
    Link Data;
    Pos Rear;
    unsigned int Volume;
};

/*Function Declaration*/
//创建一个队列(链)
LQueue CreateLQueue(unsigned int MaxSize);
//队列(链)是否为空
bool isEmptyLQ(LQueue Q);
//添加(链)
bool AddLQ(LQueue Q, ElemType E);
//删除(链)
ElemType DeleteLQ(LQueue Q);

#endif