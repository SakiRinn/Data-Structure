/*链表*/
#ifndef _LINK_H_
#define _LINK_H_
/* 说明：带头结点。 */
#include ".general.h"
#define HEAD_NODE 0xABCABC

/*Structure Declaration*/
typedef struct Node *Pos;
typedef struct Node *Link;
typedef struct Node *LoopLink;
struct Node {
    ElemType elem;
    Pos next;
};

/*Function Declaration*/
//创建链表
Link Link_init();
//创建循环链表，需要一个初始元素
LoopLink LoopLink_init(ElemType E);
//定位：返回链表L中第subs个结点的地址
Pos Link_locate(Link L, ind_t subs);
//插入(地址)：在地址pre后插入一个结点
bool Link_insertPos(Pos pre, ElemType E);
//插入(下标)：在第subs个结点后插入一个结点
bool Link_insertInd(Link L, ind_t subs, ElemType E);
//插入(尾部)：在尾部插入一个结点
bool Link_insertEnd(Link L, ElemType E);
//删除(地址)：删除地址pre指向节点的后一个结点
bool Link_deletePos(Pos pre);
//删除(下标)：删除第subs个结点
bool Link_deleteInd(Link L, ind_t subs);
//查找：返回链表L中第subs个结点的元素值
ElemType Link_search(Link L, ind_t subs);
//返回链表长度
len_t Link_len(Link L);
//销毁链表
bool Link_remove(Link L);

#endif
