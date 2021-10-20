/*队列*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include ".general.h"

/*Structure Declaration*/
typedef struct ConQueue *Queue;
struct ConQueue {
    ElemType *Data;
    Cursor Front;
    Cursor Rear;
    unsigned int MaxSize;
};

/*Function Declaration*/
//创建一个队列
Queue CreateQueue(unsigned int MaxSize);
//队列是否为满
bool IsFullQ(Queue Q);
//队列是否为空
bool IsEmptyQ(Queue Q);
//添加
bool AddQ(Queue Q, ElemType E);
//删除：成功，返回被删除元素值；失败，返回ERROR
ElemType DeleteQ(Queue Q);

#endif