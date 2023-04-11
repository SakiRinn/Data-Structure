#ifndef GENERIC_STACK_LINK
#define GENERIC_STACK_LINK(elem_t)                                             \
    typedef struct _LStack_##elem_t LStack_##elem_t;                           \
    struct _LStack_##elem_t {                                                  \
        Link_##elem_t data;                                                    \
        LPos_##elem_t top;                                                     \
        bool (*push)(LStack_##elem_t, elem_t);                                 \
        elem_t (*pop)(LStack_##elem_t);                                        \
        bool (*isEmpty)(LStack_##elem_t);                                      \
        len_t (*length)(LStack_##elem_t);                                      \
        bool (*delete)(LStack_##elem_t);                                       \
    };                                                                         \
                                                                               \
    bool LStack_##elem_t##_isEmpty(LStack_##elem_t self) {                     \
        return (self.data.head->elem == (elem_t)HEAD_NODE && !self.top)        \
                   ? true                                                      \
                   : false;                                                    \
    }                                                                          \
                                                                               \
    bool LStack_##elem_t##_push(LStack_##elem_t self, elem_t E) {              \
        if (self.data.insertPos(self.data.head, E)) {                          \
            self.top = self.data.head->next;                                   \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
                                                                               \
    elem_t LStack_##elem_t##_pop(LStack_##elem_t self) {                       \
        if (self.isEmpty(self))                                                \
            return (elem_t)ERROR;                                              \
        elem_t elem = self.top->elem;                                          \
        self.top = self.top->next;                                             \
        return self.data.removePos(self.data.head) ? elem : (elem_t)ERROR;     \
    }                                                                          \
                                                                               \
    bool LStack_##elem_t##_delete(LStack_##elem_t self) {                      \
        return self.data.delete(self.data) ? true : false;                     \
    }                                                                          \
                                                                               \
    len_t LStack_##elem_t##_length(LStack_##elem_t self) {                     \
        return self.data.length(self.data);                                    \
    }                                                                          \
                                                                               \
    LStack_##elem_t LStack_##elem_t##_init() {                                 \
        LStack_##elem_t self;                                                  \
        self.data = Link_##elem_t##_init();                                    \
        self.top = NULL;                                                       \
        self.push = LStack_##elem_t##_push;                                    \
        self.pop = LStack_##elem_t##_pop;                                      \
        self.isEmpty = LStack_##elem_t##_isEmpty;                              \
        self.length = LStack_##elem_t##_length;                                \
        self.delete = LStack_##elem_t##_delete;                                \
        return self;                                                           \
    }
#endif