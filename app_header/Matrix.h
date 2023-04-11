/*基于十字链表的矩阵*/
#ifndef _MATRIX_H_
    #define _MATRIX_H_

#include ".general.h"

/*Structure Declaration*/
enum GNodeTag {HEAD, UNIT, START};
typedef struct GNode *GPos;
typedef struct GNode *GLink;
struct GNode {
    enum GNodeTag tag;
    union {
        GLink head;
        struct {
            ind_t row;
            ind_t column;
            ElemType value;
        } unit;
    } region;
    GPos right;
    GPos down;
};
typedef GLink Matrix;

/*Function Declaration*/
//向右遍历(十字链表)
GPos GLocateRight(GLink start, ind_t subs);
//向下遍历(十字链表)
GPos GLocateDown(GLink start, ind_t subs);
//创建矩阵
Matrix CreateMatrix(ind_t MaxRow, ind_t MaxCol);
//插入矩阵中的元素
bool InsertUnit(Matrix M, ElemType E, ind_t Row, ind_t Column);
//打印矩阵
bool PrintMatrix(Matrix M);

#endif