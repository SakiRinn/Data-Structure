#include "BinaryTree.h"


int main()
{
    ETypeBiT arr[] = {5, 2, 1, 3, NOINFO, 6, 10, 12, NOINFO, 3, 11, 7, NOINFO};
    ETypeBiT ar[13]; 
    BiTree BT = CreateBiTree(arr, 13);
    rePreTrav(BT);
    putchar('\n');
    reInTrav(BT);
    putchar('\n');
    rePostTrav(BT);
    putchar('\n');
    return 0;
}