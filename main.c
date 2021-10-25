#include "BinaryTree.h"


int main()
{
    ETypeBiT arr[] = {1, 2, NOINFO, 3, 4, NOINFO, NOINFO, 5, NOINFO, NOINFO, 6, 7, NOINFO, NOINFO, 8};
    BiTree BT = PreCreateBiT(arr, 15);
    rePreTrav(BT);
    putchar('\n');
    PreTrav(BT);
    putchar('\n');
    reInTrav(BT);
    putchar('\n');
    InTrav(BT);
    putchar('\n');
    rePostTrav(BT);
    putchar('\n');
    PostTrav1(BT);
    putchar('\n');
    PostTrav2(BT);
    putchar('\n');
    PostTrav3(BT);
    putchar('\n');
    return 0;
}