#include "Calculator.h"
#include "StackLink.h"

RPN expr2RPN(char expr[]) {
    // 初始化操作符栈和RPN容器
    LStack_int opt_S = LStack_int_init();
    RPN rpn = Link_int_init();

    char *ptr = expr;
    while (ptr) {

        // 处理当前元素
        switch (*ptr) {
        case '*':
        case '/':
            while (opt_S.top &&
                   (opt_S.top->elem == '*' || opt_S.top->elem == '/'))
                rpn.insertEnd(rpn, opt_S.pop(opt_S) + OPERATOR);
            opt_S.push(opt_S, *ptr);
            break;
        case '+':
        case '-':
            while (opt_S.top &&
                   (opt_S.top->elem == '*' || opt_S.top->elem == '/' ||
                    opt_S.top->elem == '+' || opt_S.top->elem == '-'))
                rpn.insertEnd(rpn, opt_S.pop(opt_S) + OPERATOR);
            opt_S.push(opt_S, *ptr);
            break;
        case '(':
            opt_S.push(opt_S, *ptr);
            break;
        case ')':
            while (opt_S.top->elem != '(')
                rpn.insertEnd(rpn, opt_S.pop(opt_S) + OPERATOR);
            opt_S.pop(opt_S);
            break;
        default:
            if ((*ptr >= '0' && *ptr <= '9')) {
                char temp_num[NUMAXLEN] = {0};
                int i = 0;
                for (int i = 0; i < NUMAXLEN; i++) {
                    temp_num[i] = *ptr;
                    if (ptr[1] >= '0' && ptr[1] <= '9')
                        ptr++;
                    else
                        break;
                }
                rpn.insertEnd(rpn, atoi(temp_num));
            }
        }

        // next
        if (ptr[1] == '\0') {
            while (!opt_S.isEmpty(opt_S)) {
                int num = opt_S.pop(opt_S) + OPERATOR;
                if (num != ERROR)
                    rpn.insertEnd(rpn, num);
            }
            break;
        } else
            ptr++;
    }

    opt_S.delete(opt_S);
    return rpn;
}

double calcRPN(RPN rpn) {
    LStack_double calc_S = LStack_double_init();
    LPos_int data = rpn.head;
    if (data->elem != HEAD_NODE || !data->next)
        return ERROR;

    for (LPos_int ptr = data->next; ptr; ptr = ptr->next) {
        if (ptr->elem >= '*' + OPERATOR && ptr->elem <= '/' + OPERATOR) {
            if (rpn.length(rpn) < 2)
                return ERROR;
            int opt = ptr->elem - OPERATOR;
            double temp = calc_S.pop(calc_S);

            switch (opt) {
            case '+':
                calc_S.push(calc_S, calc_S.pop(calc_S) + temp);
                break;
            case '-':
                calc_S.push(calc_S, calc_S.pop(calc_S) - temp);
                break;
            case '*':
                calc_S.push(calc_S, calc_S.pop(calc_S) * temp);
                break;
            case '/':
                calc_S.push(calc_S, calc_S.pop(calc_S) / temp);
                break;
            default:
                return ERROR;
            }

        } else
            calc_S.push(calc_S, ptr->elem);
    }

    double result = calc_S.pop(calc_S);
    calc_S.delete(calc_S);
    return result;
}
