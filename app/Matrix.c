#include "Matrix.h"

GPos GLocateRight(GLink start, ind_t subs) {
    GPos ptr = start;
    for (int i = 0; i < subs; i++) {
        if (!ptr->right)
            return NULL;
        else
            ptr = ptr->right;
    }
    return ptr;
}

GPos GLocateDown(GLink start, ind_t subs) {
    GPos ptr = start;
    for (int i = 0; i < subs; i++) {
        if (!ptr->down)
            return NULL;
        else
            ptr = ptr->down;
    }
    return ptr;
}

Matrix CreateMatrix(ind_t MaxRow, ind_t MaxCol) {
    if (!MaxRow || !MaxCol)
        return NULL;
    /*Origin Node*/
    Matrix M = (Matrix)malloc(sizeof(struct GNode));
    if (!M)
        exit(EXIT_FAILURE);
    M->tag = START;
    M->region.unit.row = MaxRow;
    M->region.unit.column = MaxCol;
    M->region.unit.value = 0;
    /*Row Node*/
    GPos preR = M;
    for (int i = 0; i < MaxRow; i++) {
        GPos tmp = (GPos)malloc(sizeof(struct GNode));
        if (!tmp)
            exit(EXIT_FAILURE);
        tmp->tag = HEAD;
        tmp->region.head = NULL;
        preR->down = tmp;
        if (preR != M)
            preR->right = NULL;
        preR = preR->down;
    }
    preR->right = NULL;
    /*Column Node*/
    GPos preC = M;
    for (int i = 0; i < MaxCol; i++) {
        GPos tmp = (GPos)malloc(sizeof(struct GNode));
        tmp->tag = HEAD;
        tmp->region.head = NULL;
        preC->right = tmp;
        if (preC != M)
            preC->down = NULL;
        preC = preC->right;
    }
    preC->down = NULL;
    return M;
}

bool InsertUnit(Matrix M, ElemType E, ind_t Row, ind_t Column) {
    if (M->tag != START || Row > M->region.unit.row ||
        Column > M->region.unit.column)
        return false;
    /*Allocation*/
    GPos tmp = (GPos)malloc(sizeof(struct GNode));
    if (!tmp)
        exit(EXIT_FAILURE);
    tmp->tag = UNIT;
    tmp->region.unit.row = Row;
    tmp->region.unit.column = Column;
    tmp->region.unit.value = E;
    /*Row Location*/
    GPos ptrR = GLocateDown(M, Row);
    if (ptrR->tag == HEAD && ptrR->region.head) {
        ptrR = ptrR->region.head;
        if (ptrR->right && ptrR->right->region.unit.column == Column)
            // 首判重复
            return false;
        while (ptrR->right && !(ptrR->region.unit.column < Column &&
                                ptrR->right->region.unit.column > Column)) {
            if (ptrR->right->region.unit.column == Column)
                // 中判重复
                return false;
            ptrR = GLocateRight(ptrR, 1);
        }
        if (ptrR->region.unit.column == Column)
            // 尾判重复
            return false;
        tmp->right = ptrR->right;
        ptrR->right = tmp;
    } else {
        if (ptrR->tag != HEAD)
            return false;
        tmp->right = NULL;
        ptrR->region.head = tmp;
    }
    /*Column Location*/
    GPos ptrC = GLocateRight(M, Column);
    if (ptrC->tag == HEAD && ptrC->region.head) {
        ptrC = ptrC->region.head;
        if (ptrC->down && ptrC->down->region.unit.row == Row)
            // 首判重复
            return false;
        while (ptrC->down && !(ptrC->region.unit.row < Row &&
                               ptrC->down->region.unit.row > Row)) {
            if (ptrC->down->region.unit.row == Row)
                // 中判重复
                return false;
            ptrC = GLocateDown(ptrC, 1);
        }
        if (ptrC->region.unit.row == Row)
            // 尾判重复
            return false;
        tmp->down = ptrC->down;
        ptrC->down = tmp;
    } else {
        if (ptrC->tag != HEAD)
            return false;
        tmp->down = NULL;
        ptrC->region.head = tmp;
    }
    M->region.unit.value++;
    return true;
}

bool PrintMatrix(Matrix M) {
    if (M->tag != START)
        return false;
    GPos ptrR = M;
    for (int i = 0; i < M->region.unit.row; i++) {
        ptrR = GLocateDown(ptrR, 1);
        if (!ptrR)
            return false;
        GPos ptrC = ptrR->region.head;
        if (!ptrC) {
            // 空行填0
            for (int j = 0; j < M->region.unit.column; j++)
                printf("%-2d ", 0);
            putchar('\n');
        } else {
            // 行前补0
            for (int k = 1; k < ptrC->region.unit.column; k++)
                printf("%-2d ", 0);
            // 行中补0
            while (ptrC->right) {
                printf("%-2ld ", ptrC->region.unit.value);
                int diff =
                    ptrC->right->region.unit.column - ptrC->region.unit.column;
                for (int k = 1; k < diff; k++)
                    printf("%-2d ", 0);
                ptrC = GLocateRight(ptrC, 1);
            }
            // 行后补0
            printf("%-2ld ", ptrC->region.unit.value);
            int excess = M->region.unit.column - ptrC->region.unit.column;
            for (int k = 0; k < excess; k++)
                printf("%-2d ", 0);
            putchar('\n');
        }
    }
    return true;
}