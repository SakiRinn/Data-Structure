/**
 * @file generic/Queue.h
 * @brief 泛型队列
 *
 */
#ifndef GENERIC_QUEUE
#define GENERIC_QUEUE(elem_t)                                                  \
    typedef struct _Queue_##elem_t *Queue_##elem_t;                            \
    struct _Queue_##elem_t {                                                   \
        elem_t *data;                                                          \
        ind_t front;                                                           \
        ind_t rear;                                                            \
        ind_t maxSize;                                                         \
        bool (*add)(Queue_##elem_t, elem_t);                                   \
        elem_t (*remove)(Queue_##elem_t);                                      \
        bool (*isFull)(Queue_##elem_t);                                        \
        bool (*isEmpty)(Queue_##elem_t);                                       \
        void (*delete)(Queue_##elem_t);                                        \
        void (*print)(Queue_##elem_t);                                         \
    };                                                                         \
    static bool Queue_##elem_t##_isFull(Queue_##elem_t self) {                 \
        return (self->rear + 1) % (self->maxSize + 1) == self->front ? true    \
                                                                     : false;  \
    }                                                                          \
    static bool Queue_##elem_t##_isEmpty(Queue_##elem_t self) {                \
        return (self->front + 1) % (self->maxSize + 1) == self->rear ? true    \
                                                                     : false;  \
    }                                                                          \
    static bool Queue_##elem_t##_add(Queue_##elem_t self, elem_t E) {          \
        if (self->isFull(self))                                                \
            return false;                                                      \
        else {                                                                 \
            self->data[self->rear] = E;                                        \
            self->rear = (self->rear + 1) % (self->maxSize + 1);               \
            return true;                                                       \
        }                                                                      \
    }                                                                          \
    static elem_t Queue_##elem_t##_remove(Queue_##elem_t self) {               \
        if (self->isEmpty(self))                                               \
            return (elem_t)ERROR;                                              \
        else {                                                                 \
            elem_t value = self->data[self->front];                            \
            self->front = (self->front + 1) % (self->maxSize + 1);             \
            return value;                                                      \
        }                                                                      \
    }                                                                          \
    static void Queue_##elem_t##_delete(Queue_##elem_t self) {                 \
        free(self->data);                                                      \
        free(self);                                                            \
    }                                                                          \
    static void Queue_##elem_t##_print(Queue_##elem_t self) {                  \
        for (ind_t i = self->front; i != self->rear;                           \
             i = (i + 1) % (self->maxSize + 1)) {                              \
            if (isFloat(self->data[i]))                                        \
                printf("%g ", (double)self->data[i]);                          \
            else                                                               \
                printf("%lld ", (long long)self->data[i]);                     \
        }                                                                      \
        putchar('\n');                                                         \
    }                                                                          \
    static Queue_##elem_t Queue_##elem_t##_init(ind_t maxSize) {               \
        Queue_##elem_t self =                                                  \
            (Queue_##elem_t)malloc(sizeof(struct _Queue_##elem_t));            \
        self->data = (elem_t *)malloc((maxSize + 1) * sizeof(elem_t));         \
        if (!self->data)                                                       \
            exit(EXIT_FAILURE);                                                \
        self->front = 0;                                                       \
        self->rear = 0;                                                        \
        self->maxSize = maxSize;                                               \
        self->add = Queue_##elem_t##_add;                                      \
        self->remove = Queue_##elem_t##_remove;                                \
        self->isFull = Queue_##elem_t##_isFull;                                \
        self->isEmpty = Queue_##elem_t##_isEmpty;                              \
        self->delete = Queue_##elem_t##_delete;                                \
        self->print = Queue_##elem_t##_print;                                  \
        return self;                                                           \
    }
#endif