/*队列*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include ".general.h"
typedef int ETypeQueue;

/*Structure Declaration*/
typedef struct ConQueue *Queue;
struct ConQueue {
    ETypeQueue *Data;
    Cursor Front;
    Cursor Rear;
    Length MaxSize;
};

/*Function Declaration*/
//创建一个队列
Queue CreateQueue(Length MaxSize);
//队列是否为满
bool isFullQ(Queue Q);
//队列是否为空
bool isEmptyQ(Queue Q);
//添加
bool AddQ(Queue Q, ETypeQueue E);
//删除：成功，返回被删除元素值；失败，返回ERROR
ETypeQueue DeleteQ(Queue Q);

#endif