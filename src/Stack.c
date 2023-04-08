#include "Stack.h"

Stack Stack_init(len_t maxSize) {
    Stack S = (Stack)malloc(sizeof(Stack));
    if (!S)
        exit(EXIT_FAILURE);
    S->data = (ElemType *)malloc(maxSize * sizeof(ElemType));
    if (!S->data)
        exit(EXIT_FAILURE);
    S->top = -1;
    S->maxSize = maxSize;
    return S;
}

bool Stack_isFull(Stack S) {
    return S->top == S->maxSize - 1 ? true : false;
}

bool Stack_isEmpty(Stack S) {
    return S->top == -1 ? true : false;
}

bool Stack_push(Stack S, ElemType E) {
    if (!Stack_isFull(S)) {
        S->top++;
        S->data[S->top] = E;
        return true;
    } else
        return false;
}

ElemType Stack_pop(Stack S) {
    if (!Stack_isEmpty(S)) {
        ElemType elem = S->data[S->top];
        S->top--;
        return elem;
    } else
        return ERROR;
}