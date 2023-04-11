#include "BinaryTree.h"
#include "QueueLink.h"
#include "Queue.h"
#include "Stack.h"

GENERIC_LINK(double)
GENERIC_STACK_LINK(double)


int main()
{
    Link L = Link_init();
    /* code... */
    L.delete(L);
    return 0;
}