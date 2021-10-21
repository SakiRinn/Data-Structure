#include "Link.h"

Link CreateLink(void)
{
    Link L = (Link)malloc(sizeof(struct Node));
    if (!L)
        exit(EXIT_FAILURE);
    L->elem = HEAD_NODE;
    L->next = NULL;
    return L;
}

Pos Locate(Link L, Cursor subs)
{
    Pos ptr = L;
    for (int i = 0; i < subs; i++)
    {
        if (!ptr->next)
            return NULL;
        else
            ptr = ptr->next;
    }
    return ptr;
}

bool Insertpos(Pos pre, ElemType E)
{
    Pos tmp = (Pos)malloc(sizeof(struct Node));
    if (!tmp)
        exit(EXIT_FAILURE);
    tmp->elem = E;
    tmp->next = pre->next;
    pre->next = tmp;
    return true;
}

bool Insertcur(Link L, Cursor subs, ElemType E)
{
    Pos pre = Locate(L, subs);
    return Insertpos(pre, E);
}

bool Insertend(Link L, ElemType E)
{
    if (!L || L->elem != HEAD_NODE)
        return false;
    Pos pre = L;
    while (pre->next)
        pre = pre->next;
    return Insertpos(pre, E);
}

bool Deletepos(Pos pre)
{
    if (!pre || !pre->next)
        return false;
    Pos tmp = pre->next;
    pre->next = tmp->next;
    free(tmp);
    return true;
}

bool Deletecur(Link L, Cursor subs)
{
    if (!subs)
        return false;
    Pos pre = Locate(L, subs - 1);
    return Deletepos(pre);
}

ElemType Search(Link L, Cursor subs)
{
    Pos ptr = Locate(L, subs);
    if (!ptr)
        return ERROR;
    else
        return ptr->elem;
}

int LinkLength(Link L)
{
    int count = 0;
    Pos ptr = L;
    while (ptr->next)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

bool PrintLink(Link L)
{
    if (!L || L->elem != HEAD_NODE)
        return false;
    Pos tmp = L->next;
    while (tmp)
    {
        printf("%d ", tmp->elem);
        tmp = tmp->next;
    }
    putchar('\n');
    return true;
}

bool RemoveLink(Link L)
{
    if(!L || L->elem != HEAD_NODE)
        return false;
    while (Deletepos(L));
    free(L);
    return true;
}