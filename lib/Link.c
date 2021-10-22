#include "Link.h"

Link CreateLink()
{
    Link L = (Link)malloc(sizeof(struct Node));
    if (!L)
        exit(EXIT_FAILURE);
    L->elem = HEAD_NODE;
    L->next = NULL;
    return L;
}

Loop CreateLoop(ETypeLink E)
{
    Link L = CreateLink();
    Insertpos(L, E);
    L->next->next = L;
    return L;
}

Pos Locate(Link L, Cursor subs)
{
    if (!L || L->elem != HEAD_NODE)
        return NULL;
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

bool Insertpos(Pos pre, ETypeLink E)
{
    Pos tmp = (Pos)malloc(sizeof(struct Node));
    if (!tmp)
        exit(EXIT_FAILURE);
    tmp->elem = E;
    tmp->next = pre->next;
    pre->next = tmp;
    return true;
}

bool Insertcur(Link L, Cursor subs, ETypeLink E)
{
    if (!L || L->elem != HEAD_NODE)
        return false;
    Pos pre = Locate(L, subs);
    return Insertpos(pre, E);
}

bool Insertend(Link L, ETypeLink E)
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
    if (!L || L->elem != HEAD_NODE)
        return false;
    if (!subs)
        return false;
    Pos pre = Locate(L, subs - 1);
    return Deletepos(pre);
}

ETypeLink Search(Link L, Cursor subs)
{
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    Pos ptr = Locate(L, subs);
    if (!ptr)
        return ERROR;
    else
        return ptr->elem;
}

Length LinkLen(Link L)
{
    if (!L || L->elem != HEAD_NODE)
        return ERROR;
    int count = 0;
    Pos ptr = L;
    while (ptr->next)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

bool RemoveLink(Link L)
{
    if(!L || L->elem != HEAD_NODE)
        return false;
    while (Deletepos(L));
    free(L);
    return true;
}