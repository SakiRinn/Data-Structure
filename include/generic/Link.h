#ifndef GENERIC_LINK
#define GENERIC_LINK(elem_t)                                                   \
    typedef struct Node_##elem_t *LPos_##elem_t;                               \
    typedef struct _Link_##elem_t Link_##elem_t;                               \
    struct Node_##elem_t {                                                     \
        elem_t elem;                                                           \
        LPos_##elem_t next;                                                    \
    };                                                                         \
    struct _Link_##elem_t {                                                    \
        LPos_##elem_t head;                                                    \
        elem_t (*get)(Link_##elem_t, ind_t);                                   \
        len_t (*length)(Link_##elem_t);                                        \
        LPos_##elem_t (*locate)(Link_##elem_t, ind_t);                         \
        bool (*insertPos)(LPos_##elem_t, elem_t);                              \
        bool (*insertInd)(Link_##elem_t, ind_t, elem_t);                       \
        bool (*insertEnd)(Link_##elem_t, elem_t);                              \
        bool (*removePos)(LPos_##elem_t);                                      \
        bool (*removeInd)(Link_##elem_t, ind_t);                               \
        bool (*delete)(Link_##elem_t);                                         \
    };                                                                         \
                                                                               \
    LPos_##elem_t Link_##elem_t##_locate(Link_##elem_t self, ind_t index) {    \
        LPos_##elem_t L = self.head;                                           \
        if (!L)                                                                \
            return NULL;                                                       \
        LPos_##elem_t ptr = L;                                                 \
        for (int i = 0; i < index; i++) {                                      \
            if (!ptr->next)                                                    \
                return NULL;                                                   \
            else                                                               \
                ptr = ptr->next;                                               \
        }                                                                      \
        return ptr;                                                            \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_insertPos(LPos_##elem_t pre, elem_t E) {              \
        if (!pre)                                                              \
            return false;                                                      \
        LPos_##elem_t tmp =                                                    \
            (LPos_##elem_t)malloc(sizeof(struct Node_##elem_t));               \
        if (!tmp)                                                              \
            exit(EXIT_FAILURE);                                                \
        tmp->elem = E;                                                         \
        tmp->next = pre->next;                                                 \
        pre->next = tmp;                                                       \
        return true;                                                           \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_insertInd(Link_##elem_t self, ind_t index,            \
                                   elem_t E) {                                 \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        LPos_##elem_t pre = self.locate(self, index);                          \
        return self.insertPos(pre, E);                                         \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_insertEnd(Link_##elem_t self, elem_t E) {             \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        LPos_##elem_t pre = L;                                                 \
        while (pre->next)                                                      \
            pre = pre->next;                                                   \
        return self.insertPos(pre, E);                                         \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_removePos(LPos_##elem_t pre) {                        \
        if (!pre || !pre->next)                                                \
            return false;                                                      \
        LPos_##elem_t tmp = pre->next;                                         \
        pre->next = tmp->next;                                                 \
        free(tmp);                                                             \
        return true;                                                           \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_removeInd(Link_##elem_t self, ind_t index) {          \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        if (!index)                                                            \
            return false;                                                      \
        LPos_##elem_t pre = self.locate(self, index - 1);                      \
        return self.removePos(pre);                                            \
    }                                                                          \
                                                                               \
    elem_t Link_##elem_t##_get(Link_##elem_t self, ind_t index) {              \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return (elem_t)ERROR;                                              \
        LPos_##elem_t ptr = self.locate(self, index);                          \
        if (!ptr)                                                              \
            return (elem_t)ERROR;                                              \
        else                                                                   \
            return ptr->elem;                                                  \
    }                                                                          \
                                                                               \
    len_t Link_##elem_t##_length(Link_##elem_t self) {                         \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return ERROR;                                                      \
        len_t count = 0;                                                       \
        LPos_##elem_t ptr = L;                                                 \
        while (ptr->next) {                                                    \
            ptr = ptr->next;                                                   \
            count++;                                                           \
        }                                                                      \
        return count;                                                          \
    }                                                                          \
                                                                               \
    bool Link_##elem_t##_delete(Link_##elem_t self) {                          \
        LPos_##elem_t L = self.head;                                           \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        while (self.removePos(L))                                              \
            ;                                                                  \
        free(L);                                                               \
        return true;                                                           \
    }                                                                          \
                                                                               \
    Link_##elem_t Link_##elem_t##_init() {                                     \
        Link_##elem_t self;                                                    \
        self.head = (LPos_##elem_t)malloc(sizeof(struct Node_##elem_t));       \
        if (!self.head)                                                        \
            exit(EXIT_FAILURE);                                                \
        self.head->elem = (elem_t)HEAD_NODE;                                   \
        self.head->next = NULL;                                                \
        self.get = Link_##elem_t##_get;                                        \
        self.length = Link_##elem_t##_length;                                  \
        self.locate = Link_##elem_t##_locate;                                  \
        self.insertPos = Link_##elem_t##_insertPos;                            \
        self.insertInd = Link_##elem_t##_insertInd;                            \
        self.insertEnd = Link_##elem_t##_insertEnd;                            \
        self.removePos = Link_##elem_t##_removePos;                            \
        self.removeInd = Link_##elem_t##_removeInd;                            \
        self.delete = Link_##elem_t##_delete;                                  \
        return self;                                                           \
    }
#endif