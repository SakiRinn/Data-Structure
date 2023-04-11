#ifndef GENERIC_QUEUE_LINK
#define GENERIC_QUEUE_LINK(elem_t)                                             \
    typedef struct _LQueue_##elem_t LQueue_##elem_t;                           \
                                                                               \
    struct _LQueue_##elem_t {                                                  \
        Link_##elem_t data;                                                    \
        LPos_##elem_t rear;                                                    \
        bool (*add)(LQueue_##elem_t, elem_t);                                  \
        elem_t (*remove)(LQueue_##elem_t);                                     \
        bool (*isEmpty)(LQueue_##elem_t);                                      \
        len_t (*length)(LQueue_##elem_t);                                      \
        bool (*delete)(LQueue_##elem_t);                                       \
    };                                                                         \
                                                                               \
    bool LQueue_##elem_t##_isEmpty(LQueue_##elem_t self) {                     \
        return !(self.data.head->next) ? true : false;                         \
    }                                                                          \
                                                                               \
    bool LQueue_##elem_t##_add(LQueue_##elem_t self, elem_t E) {               \
        if (self.data.insertEnd(self.data, E)) {                               \
            self.rear = self.rear->next;                                       \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
                                                                               \
    elem_t LQueue_##elem_t##_remove(LQueue_##elem_t self) {                    \
        if (self.isEmpty(self))                                                \
            return (elem_t)ERROR;                                              \
        elem_t elem = self.data.head->next->elem;                              \
        if (self.data.removePos(self.data.head))                               \
            return elem;                                                       \
        else                                                                   \
            return (elem_t)ERROR;                                              \
    }                                                                          \
                                                                               \
    bool LQueue_##elem_t##_delete(LQueue_##elem_t self) {                      \
        return self.data.delete(self.data) ? true : false;                     \
    }                                                                          \
                                                                               \
    len_t LQueue_##elem_t##_length(LQueue_##elem_t self) {                     \
        return self.data.length(self.data);                                    \
    }                                                                          \
                                                                               \
    LQueue_##elem_t LQueue_##elem_t##_init() {                                 \
        LQueue_##elem_t self;                                                  \
        self.data = Link_##elem_t##_init();                                    \
        self.rear = self.data.head;                                            \
        self.add = LQueue_##elem_t##_add;                                      \
        self.remove = LQueue_##elem_t##_remove;                                \
        self.isEmpty = LQueue_##elem_t##_isEmpty;                              \
        self.length = LQueue_##elem_t##_length;                                \
        self.delete = LQueue_##elem_t##_delete;                                \
        return self;                                                           \
    }
#endif