/**
 * @file generic/QueueLink.h
 * @brief 泛型链队列
 *
 * @par Macro Dependency
 * @code {.C}
 * GENERIC_LINK(elem_t)
 * @endcode
 */
#ifndef GENERIC_QUEUE_LINK
#define GENERIC_QUEUE_LINK(elem_t)                                             \
    typedef struct _LQueue_##elem_t *LQueue_##elem_t;                          \
    struct _LQueue_##elem_t {                                                  \
        Link_##elem_t data;                                                    \
        LPos_##elem_t rear;                                                    \
        bool (*add)(LQueue_##elem_t, elem_t);                                  \
        elem_t (*remove)(LQueue_##elem_t);                                     \
        bool (*isEmpty)(LQueue_##elem_t);                                      \
        ind_t (*length)(LQueue_##elem_t);                                      \
        void (*delete)(LQueue_##elem_t);                                       \
        void (*print)(LQueue_##elem_t);                                        \
    };                                                                         \
    static bool LQueue_##elem_t##_isEmpty(LQueue_##elem_t self) {              \
        return !(self->data->headNode->next) ? true : false;                   \
    }                                                                          \
    static bool LQueue_##elem_t##_add(LQueue_##elem_t self, elem_t E) {        \
        if (self->data->insertEnd(self->data, E)) {                            \
            self->rear = self->rear->next;                                     \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
    static elem_t LQueue_##elem_t##_remove(LQueue_##elem_t self) {             \
        if (self->isEmpty(self))                                               \
            return (elem_t)ERROR;                                              \
        elem_t elem = self->data->headNode->next->elem;                        \
        if (self->data->length(self->data) == 1)                               \
            self->rear = self->data->headNode;                                 \
        if (self->data->removePos(self->data->headNode))                       \
            return elem;                                                       \
        else                                                                   \
            return (elem_t)ERROR;                                              \
    }                                                                          \
    static void LQueue_##elem_t##_delete(LQueue_##elem_t self) {               \
        self->data->delete(self->data);                                        \
        free(self);                                                            \
    }                                                                          \
    static ind_t LQueue_##elem_t##_length(LQueue_##elem_t self) {              \
        return self->data->length(self->data);                                 \
    }                                                                          \
    static void LQueue_##elem_t##_print(LQueue_##elem_t self) {                \
        self->data->print(self->data);                                         \
    }                                                                          \
    static LQueue_##elem_t LQueue_##elem_t##_init() {                          \
        LQueue_##elem_t self =                                                 \
            (LQueue_##elem_t)malloc(sizeof(struct _LQueue_##elem_t));          \
        self->data = Link_##elem_t##_init();                                   \
        self->rear = self->data->headNode;                                     \
        self->add = LQueue_##elem_t##_add;                                     \
        self->remove = LQueue_##elem_t##_remove;                               \
        self->isEmpty = LQueue_##elem_t##_isEmpty;                             \
        self->length = LQueue_##elem_t##_length;                               \
        self->delete = LQueue_##elem_t##_delete;                               \
        self->print = LQueue_##elem_t##_print;                                 \
        return self;                                                           \
    }
#endif