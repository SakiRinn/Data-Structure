#include "BinaryTree.h"


int main()
{
    ETypeBiT arr[] = {1, 2, NOINFO, 3, 4, NOINFO, NOINFO, 5, NOINFO, NOINFO, 6, 7, NOINFO, NOINFO, 8};
    BiTree BT = PreCreateBiT(arr, 15);
    rePostTrav(BT);
    putchar('\n');
    PostTrav(BT);
    putchar('\n');
    return 0;
}