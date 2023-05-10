#ifndef GENERIC_LINK
#define GENERIC_LINK(elem_t)                                                   \
    typedef struct Node_##elem_t *LPos_##elem_t;                               \
    typedef struct _Link_##elem_t *Link_##elem_t;                              \
    struct Node_##elem_t {                                                     \
        elem_t elem;                                                           \
        LPos_##elem_t next;                                                    \
    };                                                                         \
    struct _Link_##elem_t {                                                    \
        LPos_##elem_t headNode;                                                \
        elem_t (*get)(Link_##elem_t, ind_t);                                   \
        ind_t (*length)(Link_##elem_t);                                        \
        LPos_##elem_t (*locate)(Link_##elem_t, ind_t);                         \
        bool (*insertInd)(Link_##elem_t, ind_t, elem_t);                       \
        bool (*insertEnd)(Link_##elem_t, elem_t);                              \
        bool (*insertPos)(LPos_##elem_t, elem_t);                              \
        elem_t (*removePos)(LPos_##elem_t);                                    \
        elem_t (*removeInd)(Link_##elem_t, ind_t);                             \
        void (*delete)(Link_##elem_t);                                         \
        void (*print)(Link_##elem_t);                                          \
        elem_t *(*toArray)(Link_##elem_t);                                     \
    };                                                                         \
    static LPos_##elem_t Link_##elem_t##_locate(Link_##elem_t self,            \
                                                ind_t index) {                 \
        LPos_##elem_t L = self->headNode;                                      \
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
    static bool Link_##elem_t##_insertPos(LPos_##elem_t pre, elem_t E) {       \
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
    static bool Link_##elem_t##_insertInd(Link_##elem_t self, ind_t index,     \
                                          elem_t E) {                          \
        LPos_##elem_t L = self->headNode;                                      \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        LPos_##elem_t pre = self->locate(self, index);                         \
        return self->insertPos(pre, E);                                        \
    }                                                                          \
    static bool Link_##elem_t##_insertEnd(Link_##elem_t self, elem_t E) {      \
        LPos_##elem_t L = self->headNode;                                      \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return false;                                                      \
        LPos_##elem_t pre = L;                                                 \
        while (pre->next)                                                      \
            pre = pre->next;                                                   \
        return self->insertPos(pre, E);                                        \
    }                                                                          \
    static elem_t Link_##elem_t##_removePos(LPos_##elem_t pre) {               \
        if (!pre || !pre->next)                                                \
            return (elem_t)ERROR;                                              \
        LPos_##elem_t tmp = pre->next;                                         \
        pre->next = tmp->next;                                                 \
        elem_t value = tmp->elem;                                              \
        free(tmp);                                                             \
        return value;                                                          \
    }                                                                          \
    static elem_t Link_##elem_t##_removeInd(Link_##elem_t self, ind_t index) { \
        LPos_##elem_t L = self->headNode;                                      \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return (elem_t)ERROR;                                              \
        if (!index)                                                            \
            return (elem_t)ERROR;                                              \
        LPos_##elem_t pre = self->locate(self, index - 1);                     \
        return self->removePos(pre);                                           \
    }                                                                          \
    static elem_t Link_##elem_t##_get(Link_##elem_t self, ind_t index) {       \
        LPos_##elem_t L = self->headNode;                                      \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return (elem_t)ERROR;                                              \
        LPos_##elem_t ptr = self->locate(self, index);                         \
        if (!ptr)                                                              \
            return (elem_t)ERROR;                                              \
        else                                                                   \
            return ptr->elem;                                                  \
    }                                                                          \
    static ind_t Link_##elem_t##_length(Link_##elem_t self) {                  \
        LPos_##elem_t L = self->headNode;                                      \
        if (!L || L->elem != (elem_t)HEAD_NODE)                                \
            return (ind_t)ERROR;                                               \
        ind_t count = 0;                                                       \
        LPos_##elem_t ptr = L;                                                 \
        while (ptr->next) {                                                    \
            ptr = ptr->next;                                                   \
            count++;                                                           \
        }                                                                      \
        return count;                                                          \
    }                                                                          \
    static void Link_##elem_t##_delete(Link_##elem_t self) {                   \
        LPos_##elem_t L = self->headNode;                                      \
        while (self->removePos(L) != (elem_t)ERROR)                            \
            ;                                                                  \
        free(L);                                                               \
        free(self);                                                            \
    }                                                                          \
    static void Link_##elem_t##_print(Link_##elem_t self) {                    \
        for (LPos_##elem_t L = self->headNode->next; L; L = L->next) {         \
            if (isFloat(L->elem))                                              \
                printf("%g ", (double)L->elem);                                \
            else                                                               \
                printf("%lld ", (long long)L->elem);                           \
        }                                                                      \
        putchar('\n');                                                         \
    }                                                                          \
    elem_t *Link_##elem_t##_toArray(Link_##elem_t self) {                      \
        if (!self->length(self))                                               \
            exit(EXIT_FAILURE);                                                \
        elem_t *array =                                                        \
            (elem_t *)malloc((self->length(self) + 1) * sizeof(elem_t));       \
        memset(array, 0, self->length(self) + 1);                              \
        LPos_##elem_t ptr = self->headNode->next;                              \
        for (int i = 0; i < self->length(self); i++) {                         \
            array[i] = ptr->elem;                                              \
            ptr = ptr->next;                                                   \
        }                                                                      \
        return array;                                                          \
    }                                                                          \
    static Link_##elem_t Link_##elem_t##_init() {                              \
        Link_##elem_t self =                                                   \
            (Link_##elem_t)malloc(sizeof(struct _Link_##elem_t));              \
        self->headNode = (LPos_##elem_t)malloc(sizeof(struct Node_##elem_t));  \
        if (!self->headNode)                                                   \
            exit(EXIT_FAILURE);                                                \
        self->headNode->elem = (elem_t)HEAD_NODE;                              \
        self->headNode->next = NULL;                                           \
        self->get = Link_##elem_t##_get;                                       \
        self->length = Link_##elem_t##_length;                                 \
        self->locate = Link_##elem_t##_locate;                                 \
        self->insertPos = Link_##elem_t##_insertPos;                           \
        self->insertInd = Link_##elem_t##_insertInd;                           \
        self->insertEnd = Link_##elem_t##_insertEnd;                           \
        self->removePos = Link_##elem_t##_removePos;                           \
        self->removeInd = Link_##elem_t##_removeInd;                           \
        self->delete = Link_##elem_t##_delete;                                 \
        self->print = Link_##elem_t##_print;                                   \
        self->toArray = Link_##elem_t##_toArray;                               \
        return self;                                                           \
    }
#endif