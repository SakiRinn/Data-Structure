#ifndef GENERIC_STACK_LINK
#define GENERIC_STACK_LINK(elem_t)                                             \
    typedef struct _LStack_##elem_t *LStack_##elem_t;                          \
    struct _LStack_##elem_t {                                                  \
        Link_##elem_t data;                                                    \
        LPos_##elem_t top;                                                     \
        bool (*push)(LStack_##elem_t, elem_t);                                 \
        elem_t (*pop)(LStack_##elem_t);                                        \
        bool (*isEmpty)(LStack_##elem_t);                                      \
        ind_t (*length)(LStack_##elem_t);                                      \
        void (*delete)(LStack_##elem_t);                                       \
        void (*print)(LStack_##elem_t);                                        \
    };                                                                         \
    static bool LStack_##elem_t##_isEmpty(LStack_##elem_t self) {              \
        return (self->data->headNode->elem == (elem_t)HEAD_NODE && !self->top) \
                   ? true                                                      \
                   : false;                                                    \
    }                                                                          \
    static bool LStack_##elem_t##_push(LStack_##elem_t self, elem_t E) {       \
        if (self->data->insertPos(self->data->headNode, E)) {                  \
            self->top = self->data->headNode->next;                            \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
    static elem_t LStack_##elem_t##_pop(LStack_##elem_t self) {                \
        if (self->isEmpty(self))                                               \
            return (elem_t)ERROR;                                              \
        elem_t elem = self->top->elem;                                         \
        self->top = self->top->next;                                           \
        return self->data->removePos(self->data->headNode) ? elem              \
                                                           : (elem_t)ERROR;    \
    }                                                                          \
    static void LStack_##elem_t##_delete(LStack_##elem_t self) {               \
        return self->data->delete(self->data);                                \
    }                                                                          \
    static ind_t LStack_##elem_t##_length(LStack_##elem_t self) {              \
        return self->data->length(self->data);                                 \
    }                                                                          \
    static void LStack_##elem_t##_print(LStack_##elem_t self) {                \
        printf("[Warning] Print in reverse order.\n");                         \
        self->data->print(self->data);                                         \
    }                                                                          \
    static LStack_##elem_t LStack_##elem_t##_init() {                          \
        LStack_##elem_t self =                                                 \
            (LStack_##elem_t)malloc(sizeof(struct _LStack_##elem_t));          \
        self->data = Link_##elem_t##_init();                                   \
        self->top = NULL;                                                      \
        self->push = LStack_##elem_t##_push;                                   \
        self->pop = LStack_##elem_t##_pop;                                     \
        self->isEmpty = LStack_##elem_t##_isEmpty;                             \
        self->length = LStack_##elem_t##_length;                               \
        self->delete = LStack_##elem_t##_delete;                               \
        self->print = LStack_##elem_t##_print;                                 \
        return self;                                                           \
    }
#endif