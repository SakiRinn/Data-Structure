// #include "Calculator.h"
#include ".general.h"
#include "Stack.h"
#include "StackLink.h"

GENERIC_STACK(int)

int main() {
    Stack_int LS = Stack_int_init(100);

    for (int i = 0; i < 77; i++)
        LS->push(LS, i + 1);
    LS->pop(LS);
    LS->print(LS);

    return 0;
}