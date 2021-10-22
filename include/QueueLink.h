/*队列(链)*/
#ifndef _QUEUE_LINK_H_
#define _QUEUE_LINK_H_
/* 说明：
链队列的前指针Front就是链表头结点的指针。 */
#include ".general.h"
#include "Link.h"
typedef long ETypeLQueue;

/*Structure Declaration*/
typedef struct ConLQueue *LQueue;
struct ConLQueue {
    Link Data;
    Pos Rear;
};

/*Function Declaration*/
//创建一个队列(链)
LQueue CreateLQueue();
//队列(链)是否为空
bool isEmptyLQ(LQueue Q);
//添加(链)
bool AddLQ(LQueue Q, ETypeLQueue E);
//删除(链)
ETypeLQueue DeleteLQ(LQueue Q);
//销毁链队列
bool RemoveLQ(LQueue Q);
//返回链队列长度
Length LQueueLen(LQueue Q);

#endif