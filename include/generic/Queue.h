#ifndef GENERIC_QUEUE
#define GENERIC_QUEUE(elem_t)                                                  \
    typedef struct _Queue_##elem_t Queue_##elem_t;                             \
    struct _Queue_##elem_t {                                                   \
        elem_t *data;                                                          \
        ind_t front;                                                           \
        ind_t rear;                                                            \
        len_t maxSize;                                                         \
        bool (*add)(Queue_##elem_t, elem_t);                                   \
        elem_t (*remove)(Queue_##elem_t);                                      \
        bool (*isFull)(Queue_##elem_t);                                        \
        bool (*isEmpty)(Queue_##elem_t);                                       \
        void (*delete)(Queue_##elem_t);                                        \
    };                                                                         \
                                                                               \
    bool Queue_##elem_t##_isFull(Queue_##elem_t self) {                        \
        return (self.rear + 1) % (self.maxSize) == self.front ? true : false;  \
    }                                                                          \
                                                                               \
    bool Queue_##elem_t##_isEmpty(Queue_##elem_t self) {                       \
        return self.front == self.rear ? true : false;                         \
    }                                                                          \
                                                                               \
    bool Queue_##elem_t##_add(Queue_##elem_t self, elem_t E) {                 \
        if (Queue_##elem_t##_isFull(self))                                     \
            return false;                                                      \
        else {                                                                 \
            self.rear = (self.rear + 1) % self.maxSize;                        \
            self.data[self.rear] = E;                                          \
            return true;                                                       \
        }                                                                      \
    }                                                                          \
                                                                               \
    elem_t Queue_##elem_t##_remove(Queue_##elem_t self) {                      \
        if (Queue_##elem_t##_isEmpty(self))                                    \
            return (elem_t)ERROR;                                              \
        else {                                                                 \
            self.front = (self.front + 1) % self.maxSize;                      \
            return self.data[self.front];                                      \
        }                                                                      \
    }                                                                          \
                                                                               \
    void Queue_##elem_t##_delete(Queue_##elem_t self) { free(self.data); }     \
                                                                               \
    Queue_##elem_t Queue_##elem_t##_init(len_t maxSize) {                      \
        Queue_##elem_t self;                                                   \
        self.data = (elem_t *)malloc((maxSize + 1) * sizeof(elem_t));          \
        if (!self.data)                                                        \
            exit(EXIT_FAILURE);                                                \
        self.front = -1;                                                       \
        self.rear = -1;                                                        \
        self.maxSize = maxSize;                                                \
        self.add = Queue_##elem_t##_add;                                       \
        self.remove = Queue_##elem_t##_remove;                                 \
        self.isFull = Queue_##elem_t##_isFull;                                 \
        self.isEmpty = Queue_##elem_t##_isEmpty;                               \
        self.delete = Queue_##elem_t##_delete;                                 \
        return self;                                                           \
    }
#endif