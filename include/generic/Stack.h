#ifndef GENERIC_STACK
#define GENERIC_STACK(elem_t)                                                  \
    typedef struct _Stack_##elem_t Stack_##elem_t;                             \
    struct _Stack_##elem_t {                                                   \
        elem_t *data;                                                          \
        ind_t top;                                                             \
        len_t maxSize;                                                         \
        bool (*push)(Stack_##elem_t, elem_t);                                  \
        elem_t (*pop)(Stack_##elem_t);                                         \
        bool (*isFull)(Stack_##elem_t);                                        \
        bool (*isEmpty)(Stack_##elem_t);                                       \
        void (*delete)(Stack_##elem_t);                                        \
    };                                                                         \
                                                                               \
    bool Stack_##elem_t##_isFull(Stack_##elem_t self) {                        \
        return self.top == self.maxSize - 1 ? true : false;                    \
    }                                                                          \
                                                                               \
    bool Stack_##elem_t##_isEmpty(Stack_##elem_t self) {                       \
        return self.top == -1 ? true : false;                                  \
    }                                                                          \
                                                                               \
    bool Stack_##elem_t##_push(Stack_##elem_t self, elem_t E) {                \
        if (!self.isFull(self)) {                                              \
            self.top++;                                                        \
            self.data[self.top] = E;                                           \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
                                                                               \
    elem_t Stack_##elem_t##_pop(Stack_##elem_t self) {                         \
        if (!self.isEmpty(self)) {                                             \
            elem_t elem = self.data[self.top];                                 \
            self.top--;                                                        \
            return elem;                                                       \
        } else                                                                 \
            return (elem_t)ERROR;                                              \
    }                                                                          \
                                                                               \
    void Stack_##elem_t##_delete(Stack_##elem_t self) { free(self.data); }     \
                                                                               \
    Stack_##elem_t Stack_##elem_t##_init(len_t maxSize) {                      \
        Stack_##elem_t self;                                                   \
        self.data = (elem_t *)malloc(maxSize * sizeof(elem_t));                \
        if (!self.data)                                                        \
            exit(EXIT_FAILURE);                                                \
        self.top = -1;                                                         \
        self.maxSize = maxSize;                                                \
        self.push = Stack_##elem_t##_push;                                     \
        self.pop = Stack_##elem_t##_pop;                                       \
        self.isFull = Stack_##elem_t##_isFull;                                 \
        self.isEmpty = Stack_##elem_t##_isEmpty;                               \
        return self;                                                           \
    }
#endif
