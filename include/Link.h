/**
 * @file Link.h
 * @brief 链表
 *
 */
#ifndef _LINK_H_
#define _LINK_H_

#include <stdbool.h>
#include ".general.h"
#include "generic/Link.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

// 头结点的elem，用于标记头结点
#define HEAD_NODE 0xCDC

typedef struct Node *LPos;
typedef struct _Link *Link;
struct Node {
    ElemType elem;
    LPos next;
};
struct _Link {
    // attribute
    LPos headNode;
    // method
    ElemType    (*get)          (Link, ind_t);
    ind_t       (*length)       (Link);
    LPos        (*locate)       (Link, ind_t);
    bool        (*insertInd)    (Link, ind_t, ElemType);
    bool        (*insertEnd)    (Link, ElemType);
    bool        (*insertPos)    (LPos, ElemType);
    ElemType    (*removePos)    (LPos);
    ElemType    (*removeInd)    (Link, ind_t);
    void        (*delete)       (Link);
    void        (*print)        (Link);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 初始化
Link Link_init();
// 定位: 返回链表L中第index个结点的地址
LPos Link_locate(Link self, ind_t index);
// 插入 (按地址): 在地址pre后插入一个结点
bool Link_insertPos(LPos pre, ElemType E);
// 插入 (按下标): 在第index个结点后插入一个结点
bool Link_insertInd(Link self, ind_t index, ElemType E);
// 尾插: 在尾部插入一个结点
bool Link_insertEnd(Link self, ElemType E);
// 删除 (按地址): 删除地址pre指向节点的后一个结点
ElemType Link_removePos(LPos pre);
// 删除 (按下标): 删除第index个结点
ElemType Link_removeInd(Link self, ind_t index);
// 查找: 返回链表L中第index个结点的元素值
ElemType Link_get(Link self, ind_t index);
// 返回长度
ind_t Link_length(Link self);
// 销毁
void Link_delete(Link self);
// 打印
void Link_print(Link self);


#endif
