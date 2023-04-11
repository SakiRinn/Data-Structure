#include "Calculator.h"
#include "StackLink.h"

Link RevPolish(char expr[]) {
    Link res = Link_init();
    LStack opestack = LStack_init();
    char *ptr = expr;
    while (ptr) {
        /*judgement*/
        switch (*ptr) {
        case '*':
        case '/':
            while (opestack->top &&
                   (opestack->top->elem == '*' || opestack->top->elem == '/'))
                Link_insertEnd(res, LStack_pop(opestack) + OPTOR);
            LStack_push(opestack, *ptr);
            break;
        case '+':
        case '-':
            while (opestack->top &&
                   (opestack->top->elem == '*' || opestack->top->elem == '/' ||
                    opestack->top->elem == '+' || opestack->top->elem == '-'))
                Link_insertEnd(res, LStack_pop(opestack) + OPTOR);
            LStack_push(opestack, *ptr);
            break;
        case '(':
            LStack_push(opestack, *ptr);
            break;
        case ')':
            while (opestack->top->elem != '(')
                Link_insertEnd(res, LStack_pop(opestack) + OPTOR);
            LStack_pop(opestack);
            break;
        default:
            if (*ptr >= '0' && *ptr <= '9') {
                char tmpnum[NUMAXLEN] = {0};
                for (int i = 0; i < NUMAXLEN; i++) {
                    tmpnum[i] = *ptr;
                    if (ptr[1] >= '0' && ptr[1] <= '9')
                        ptr++;
                    else
                        break;
                }
                Link_insertEnd(res, atoi(tmpnum));
            }
        }
        /*next*/
        if (ptr[1] == '\0') {
            while (!LStack_isEmpty(opestack)) {
                ElemType num = LStack_pop(opestack) + OPTOR;
                if (num != ERROR)
                    Link_insertEnd(res, num);
            }
            break;
        } else
            ptr++;
    }
    return res;
}

ElemType CalcRev(Link revp) {
    if (revp->elem != HEAD_NODE || !revp->next)
        return ERROR;
    LStack calcstack = LStack_init();
    LPos ptr = revp->next;
    while (ptr) {
        if (ptr->elem >= '*' + OPTOR && ptr->elem <= '/' + OPTOR) {
            if (LStack_length(calcstack) < 2)
                return ERROR;
            int ope = ptr->elem - OPTOR;
            ElemType temp = LStack_pop(calcstack);
            switch (ope) {
            case '+':
                LStack_push(calcstack, LStack_pop(calcstack) + temp);
                break;
            case '-':
                LStack_push(calcstack, LStack_pop(calcstack) - temp);
                break;
            case '*':
                LStack_push(calcstack, LStack_pop(calcstack) * temp);
                break;
            case '/':
                LStack_push(calcstack, LStack_pop(calcstack) / temp);
                break;
            default:
                return ERROR;
            }
        } else
            LStack_push(calcstack, ptr->elem);
        ptr = ptr->next;
    }
    return LStack_pop(calcstack);
}