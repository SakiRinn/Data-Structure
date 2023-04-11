/*链表*/
#ifndef _LINK_H_
#define _LINK_H_

#include <stdbool.h>
#include ".general.h"
#define HEAD_NODE 0xABCABC
#include "generic/Link.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef struct Node *LPos;
typedef struct _Link Link;
struct Node {
    ElemType elem;
    LPos next;
};
struct _Link {
    // attribute
    LPos head;
    // method
    ElemType    (*get)          (Link, ind_t);
    len_t       (*length)       (Link);
    LPos        (*locate)       (Link, ind_t);
    bool        (*insertInd)    (Link, ind_t, ElemType);
    bool        (*insertEnd)    (Link, ElemType);
    bool        (*insertPos)    (LPos, ElemType);
    bool        (*removePos)    (LPos);
    bool        (*removeInd)    (Link, ind_t);
    bool        (*delete)       (Link);
};


//-------------------------------------
// Method Declaration
//-------------------------------------

// 创建链表
Link Link_init();
// 定位：返回链表L中第subs个结点的地址
LPos Link_locate(Link self, ind_t subs);
// 插入(地址)：在地址pre后插入一个结点
bool Link_insertPos(LPos pre, ElemType E);
// 插入(下标)：在第subs个结点后插入一个结点
bool Link_insertInd(Link self, ind_t subs, ElemType E);
// 插入(尾部)：在尾部插入一个结点
bool Link_insertEnd(Link self, ElemType E);
// 删除(地址)：删除地址pre指向节点的后一个结点
bool Link_removePos(LPos pre);
// 删除(下标)：删除第subs个结点
bool Link_removeInd(Link self, ind_t subs);
// 查找：返回链表L中第subs个结点的元素值
ElemType Link_get(Link self, ind_t subs);
// 返回链表长度
len_t Link_length(Link self);
// 销毁链表
bool Link_delete(Link self);


#endif
