#ifndef GENERIC_STACK
#define GENERIC_STACK(elem_t)                                                  \
    typedef struct _Stack_##elem_t *Stack_##elem_t;                            \
    struct _Stack_##elem_t {                                                   \
        elem_t *data;                                                          \
        ind_t top;                                                             \
        ind_t maxSize;                                                         \
        bool (*push)(Stack_##elem_t, elem_t);                                  \
        elem_t (*pop)(Stack_##elem_t);                                         \
        bool (*isFull)(Stack_##elem_t);                                        \
        bool (*isEmpty)(Stack_##elem_t);                                       \
        void (*delete)(Stack_##elem_t);                                        \
        void (*print)(Stack_##elem_t);                                         \
    };                                                                         \
    static bool Stack_##elem_t##_isFull(Stack_##elem_t self) {                 \
        return self->top == self->maxSize - 1 ? true : false;                  \
    }                                                                          \
    static bool Stack_##elem_t##_isEmpty(Stack_##elem_t self) {                \
        return self->top == -1 ? true : false;                                 \
    }                                                                          \
    static bool Stack_##elem_t##_push(Stack_##elem_t self, elem_t E) {         \
        if (!self->isFull(self)) {                                             \
            self->top++;                                                       \
            self->data[self->top] = E;                                         \
            return true;                                                       \
        } else                                                                 \
            return false;                                                      \
    }                                                                          \
    static elem_t Stack_##elem_t##_pop(Stack_##elem_t self) {                  \
        if (!self->isEmpty(self)) {                                            \
            elem_t elem = self->data[self->top];                               \
            self->top--;                                                       \
            return elem;                                                       \
        } else                                                                 \
            return ERROR;                                                      \
    }                                                                          \
    static void Stack_##elem_t##_delete(Stack_##elem_t self) {                 \
        free(self->data);                                                      \
        free(self);                                                            \
    }                                                                          \
    static void Stack_##elem_t##_print(Stack_##elem_t self) {                  \
        for (int i = 0; i < self->top + 1; i++) {                              \
            if (isFloat(self->data[i]))                                        \
                printf("%g ", (double)self->data[i]);                          \
            else                                                               \
                printf("%lld ", (long long)self->data[i]);                     \
        }                                                                      \
        putchar('\n');                                                         \
    }                                                                          \
    static Stack_##elem_t Stack_##elem_t##_init(ind_t maxSize) {               \
        Stack_##elem_t self =                                                  \
            (Stack_##elem_t)malloc(sizeof(struct _Stack_##elem_t));            \
        self->data = (elem_t *)malloc(maxSize * sizeof(elem_t));               \
        if (!self->data)                                                       \
            exit(EXIT_FAILURE);                                                \
        self->top = -1;                                                        \
        self->maxSize = maxSize;                                               \
        self->push = Stack_##elem_t##_push;                                    \
        self->pop = Stack_##elem_t##_pop;                                      \
        self->isFull = Stack_##elem_t##_isFull;                                \
        self->isEmpty = Stack_##elem_t##_isEmpty;                              \
        self->delete = Stack_##elem_t##_delete;                                \
        self->print = Stack_##elem_t##_print;                                  \
        return self;                                                           \
    }
#endif
