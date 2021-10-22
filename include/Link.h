/*链表*/
#ifndef _LINK_H_
#define _LINK_H_
/* 说明：带头结点。 */
#include ".general.h"
#define HEAD_NODE 0xABCABC
typedef long ETypeLink;

/*Structure Declaration*/
typedef struct Node *Pos;
typedef struct Node *Link;
typedef struct Node *Loop;
struct Node {
    ETypeLink elem;
    Pos next;
};

/*Function Declaration*/
//创建链表
Link CreateLink();
//创建循环链表，需要一个初始元素
Loop CreateLoop(ETypeLink E);
//定位：返回链表L中第subs个结点的地址
Pos Locate(Link L, Cursor subs);
//插入(地址)：在地址pre后插入一个结点
bool Insertpos(Pos pre, ETypeLink E);
//插入(游标)：在第subs个结点后插入一个结点
bool Insertcur(Link L, Cursor subs, ETypeLink E);
//插入(尾部)：在尾部插入一个结点
bool Insertend(Link L, ETypeLink E);
//删除(地址)：删除地址pre指向节点的后一个结点
bool Deletepos(Pos pre);
//删除(游标)：删除第subs个结点
bool Deletecur(Link L, Cursor subs);
//查找：返回链表L中第subs个结点的元素值
ETypeLink Search(Link L, Cursor subs);
//返回链表长度
Length LinkLen(Link L);
//销毁链表
bool RemoveLink(Link L);

#endif