#include <string.h>
#include "Calculator.h"
#include "StackLink.h"
#include "QueueLink.h"

GENERIC_LINK(int)
GENERIC_QUEUE_LINK(int)
GENERIC_STACK_LINK(int)
GENERIC_LINK(double)
GENERIC_STACK_LINK(double)

RPN expr2RPN(char expr[]) {
    RPN rpn = Link_init();

    LStack_double opt_S = LStack_double_init();     // 存操作符
    LStack_int weight_S = LStack_int_init();        // 存上一个操作符的权重
    LQueue_int num_Q = LQueue_int_init();           // 实则为char队列, 存数字字符串

    for (int i = 0; i < strlen(expr); i++) {

        /* 数字部分 */
        if ((expr[i] >= '0' && expr[i] <= '9') || expr[i] == '.') {
            num_Q->add(num_Q, expr[i]);
            continue;
        }
        else {
            char num_string[MAX_DIGIT] = {'\0'};
            int j = 0;
            while (!num_Q->isEmpty(num_Q)) {
                num_string[j] = (char)num_Q->remove(num_Q);
                j++;
            }
            if (j != 0)
                rpn->insertEnd(rpn, (ElemType)strtod(num_string, NULL));
        }

        /* 操作符部分 */
        int weight;
        switch (expr[i]) {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '(':
            // 左括号: 操作符入栈
            weight_S->push(weight_S, 0);
            opt_S->push(opt_S, expr[i]);
            continue;
        case ')':
            // 右括号: 操作符逐个出栈, 直到遇到左括号
            while (!opt_S->isEmpty(opt_S) && opt_S->top->elem != '(') {
                weight_S->pop(weight_S);
                rpn->insertEnd(rpn, (ElemType)(opt_S->pop(opt_S) + OPERATOR));
            }
            weight_S->pop(weight_S);
            opt_S->pop(opt_S);
            continue;
        case ' ':
            continue;
        default:
            exit(EXIT_FAILURE);
        }

        // 如果当前操作符权重不大于栈顶权重, 则栈顶操作符出栈
        while (!weight_S->isEmpty(weight_S) && weight <= weight_S->top->elem) {
            weight_S->pop(weight_S);
            rpn->insertEnd(rpn, (ElemType)(opt_S->pop(opt_S) + OPERATOR));
        }

        // 入栈
        weight_S->push(weight_S, weight);
        opt_S->push(opt_S, expr[i]);
    }

    // 输出最后一个数
    char num_string[MAX_DIGIT] = {'\0'};
    int j = 0;
    while (!num_Q->isEmpty(num_Q)) {
        num_string[j] = (char)num_Q->remove(num_Q);
        j++;
    }
    if (j != 0)
        rpn->insertEnd(rpn, (ElemType)strtod(num_string, NULL));
    // 清空操作符栈
    while (!opt_S->isEmpty(opt_S))
        rpn->insertEnd(rpn, (ElemType)(opt_S->pop(opt_S) + OPERATOR));

    opt_S->delete(opt_S);
    weight_S->delete(weight_S);
    num_Q->delete(num_Q);
    return rpn;
}

double calcRPN(RPN rpn) {
    LStack_double calc_S = LStack_double_init();
    LPos data = rpn->headNode;
    if (data->elem != HEAD_NODE || !data->next)
        return ERROR;

    for (LPos ptr = data->next; ptr; ptr = ptr->next) {
        if (ptr->elem >= '*' + OPERATOR && ptr->elem <= '/' + OPERATOR) {
            if (rpn->length(rpn) < 2)
                return ERROR;
            int opt = ptr->elem - OPERATOR;
            double temp = calc_S->pop(calc_S);

            switch (opt) {
            case '+':
                calc_S->push(calc_S, calc_S->pop(calc_S) + temp);
                break;
            case '-':
                calc_S->push(calc_S, calc_S->pop(calc_S) - temp);
                break;
            case '*':
                calc_S->push(calc_S, calc_S->pop(calc_S) * temp);
                break;
            case '/':
                calc_S->push(calc_S, calc_S->pop(calc_S) / temp);
                break;
            default:
                return ERROR;
            }

        } else
            calc_S->push(calc_S, ptr->elem);
    }

    double result = calc_S->pop(calc_S);
    calc_S->delete(calc_S);
    return result;
}

void printRPN(RPN rpn) {
    LPos_double data = rpn->headNode;
    for (LPos_double ptr = data->next; ptr; ptr = ptr->next) {
        if (equal(ptr->elem, '+' + OPERATOR) && ptr->elem <= '/' + OPERATOR)
            printf("%c ", (int)ptr->elem - OPERATOR);
        else
            printf("%d ", ptr->elem);
    }
    putchar('\n');
}
