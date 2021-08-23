#include "Calculator.h"

Link RevPolish(char expr[])
{
    Link res = CreateLink();
    LStack opestack = CreateLStack();
    char *ptr = expr;
    while(ptr) {
        /*judgement*/
        switch(*ptr) {
            case '*': case '/': 
                while(opestack->Top && (opestack->Top->elem == '*' || opestack->Top->elem == '/')) 
                    Insertend(res, LPop(opestack) + OPTOR);
                LPush(opestack, *ptr);
                break;
            case '+': case '-':
                while(opestack->Top && (opestack->Top->elem == '*' || opestack->Top->elem == '/' 
                || opestack->Top->elem == '+' || opestack->Top->elem == '-')) 
                    Insertend(res, LPop(opestack) + OPTOR);
                LPush(opestack, *ptr);
                break;
            case '(': 
                LPush(opestack, *ptr);
                break;
            case ')': 
                while(opestack->Top->elem != '(')
                    Insertend(res, LPop(opestack) + OPTOR);
                LPop(opestack);
                break;
            default:
                if(*ptr >= '0' && *ptr <= '9') {
                    char tmpnum[NUMAXLEN] = {0};
                    for(int i = 0; i < NUMAXLEN; i++) {
                        tmpnum[i] = *ptr;
                        if(ptr[1] >= '0' && ptr[1] <= '9') 
                            ptr++;
                        else break;
                    }
                    Insertend(res, atoi(tmpnum));
                }
        }
        /*next*/
        if(ptr[1] == '\0') {
            while(opestack->Volume) {
                ElemType num = LPop(opestack) + OPTOR;
                if(num != ERROR)
                    Insertend(res, num);
            }
            break;
        }
        else ptr++;
    }
    return res;
}

ElemType CalcRev(Link revp)
{
    if(revp->elem != HEAD_NODE || !revp->next)
        return ERROR;
    LStack calcstack = CreateLStack();
    Pos ptr = revp->next;
    while(ptr) {
        if(ptr->elem >= '*' + OPTOR && ptr->elem <= '/' + OPTOR) {
            if(calcstack->Volume < 2)
                return ERROR;
            int ope = ptr->elem - OPTOR;
            ElemType temp = LPop(calcstack);
            switch(ope) {
                case '+':
                    LPush(calcstack, LPop(calcstack) + temp);
                    break;
                case '-':
                    LPush(calcstack, LPop(calcstack) - temp);
                    break;
                case '*':
                    LPush(calcstack, LPop(calcstack) * temp);
                    break;
                case '/':
                    LPush(calcstack, LPop(calcstack) / temp);
                    break;
                default:
                    return ERROR;
            }
        } else 
            LPush(calcstack, ptr->elem);
        ptr = ptr->next;
    }
    return LPop(calcstack);
}