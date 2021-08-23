/*基于十字链表的矩阵*/
#ifndef _MATRIX_H_
    #define _MATRIX_H_

#include ".general.h"

/*Structure Declaration*/
enum Type {HEAD, UNIT, START};
typedef struct GNode *GPos;
typedef struct GNode *GLink;
struct GNode {
    enum Type tag;
    union {
        GLink head;
        struct {
            Cursor row;
            Cursor column;
            ElemType value;
        } unit;
    } region;
    GPos right;
    GPos down;
};
typedef GLink Matrix;

/*Function Declaration*/
//向右遍历(十字链表)
GPos GLocateRight(GLink start, Cursor subs);
//向下遍历(十字链表)
GPos GLocateDown(GLink start, Cursor subs);
//创建矩阵
Matrix CreateMatrix(Cursor MaxRow, Cursor MaxCol);
//插入矩阵中的元素
bool InsertUnit(Matrix M, ElemType E, Cursor Row, Cursor Column);
//打印矩阵
bool PrintMatrix(Matrix M);

#endif