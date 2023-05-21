#include <string.h>
#include "Calculator.h"
#include "StackLink.h"
#include "QueueLink.h"

GENERIC_LINK(int)
GENERIC_QUEUE_LINK(int)
GENERIC_STACK_LINK(int)
GENERIC_LINK(double)
GENERIC_STACK_LINK(double)

Expr expr2RPN(char exprString[]) {
    Expr rpn = Link_init();

    LStack_double optS = LStack_double_init();     // 存操作符
    LStack_int weightS = LStack_int_init();        // 存操作符的权重
    LQueue_int numQ = LQueue_int_init();           // 实则为char队列, 存数字字符串

    for (int i = 0; i < strlen(exprString); i++) {

        /* 数字部分 */
        if ((exprString[i] >= '0' && exprString[i] <= '9') || exprString[i] == '.') {
            // 若为数字, 入numQ队列, 然后直接快进到下个循环
            numQ->add(numQ, exprString[i]);
            continue;
        }
        else {
            // 若不为数字, 将numQ队列的字符转换为数字后加到rpn中, 然后清空队列
            // 不快进, 而是继续之后的“操作符部分”
            char num_string[MAX_DIGIT] = {'\0'};
            int j = 0;
            while (!numQ->isEmpty(numQ)) {
                num_string[j] = (char)numQ->remove(numQ);
                j++;
            }
            if (j != 0)
                rpn->insertEnd(rpn, (ElemType)strtod(num_string, NULL));
        }

        /* 操作符部分 */
        int weight;
        switch (exprString[i]) {
        // 加减乘除: 赋予权重
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        // 左括号: 权重为0, 入栈后快进
        case '(':
            weightS->push(weightS, 0);
            optS->push(optS, exprString[i]);
            continue;
        // 右括号: 操作符逐个出栈, 直到遇到左括号
        case ')':
            while (!optS->isEmpty(optS) && optS->top->elem != '(') {
                weightS->pop(weightS);
                rpn->insertEnd(rpn, (ElemType)(optS->pop(optS) + OPERATOR));
            }
            weightS->pop(weightS);
            optS->pop(optS);
            continue;
        // 空格: 快进
        case ' ':
            continue;
        default:
            exit(EXIT_FAILURE);
        }

        // 如果当前操作符权重不大于栈顶权重, 则栈顶操作符出栈
        while (!weightS->isEmpty(weightS) && weight <= weightS->top->elem) {
            weightS->pop(weightS);
            rpn->insertEnd(rpn, (ElemType)(optS->pop(optS) + OPERATOR));
        }

        // 操作符入栈
        weightS->push(weightS, weight);
        optS->push(optS, exprString[i]);
    }

    // 输出最后一个数
    char num_string[MAX_DIGIT] = {'\0'};
    int j = 0;
    while (!numQ->isEmpty(numQ)) {
        num_string[j] = (char)numQ->remove(numQ);
        j++;
    }
    if (j != 0)
        rpn->insertEnd(rpn, (ElemType)strtod(num_string, NULL));
    // 清空操作符栈
    while (!optS->isEmpty(optS))
        rpn->insertEnd(rpn, (ElemType)(optS->pop(optS) + OPERATOR));

    optS->delete(optS);
    weightS->delete(weightS);
    numQ->delete(numQ);
    return rpn;
}

ElemType calcRPN(Expr rpn) {
    LStack numS = LStack_init();
    if (rpn->headNode->elem != HEAD_NODE || rpn->length(rpn) < 2)
        return ERROR;

    for (LPos ptr = rpn->headNode->next; ptr; ptr = ptr->next) {
        int tmp;
        switch (ptr->elem) {
        /* 操作符部分 */
        case '+' + OPERATOR:
            numS->push(numS, numS->pop(numS) + numS->pop(numS));
            break;
        case '-' + OPERATOR:
            tmp = numS->pop(numS);
            numS->push(numS, numS->pop(numS) - tmp);
            break;
        case '*' + OPERATOR:
            numS->push(numS, numS->pop(numS) * numS->pop(numS));
            break;
        case '/' + OPERATOR:
            tmp = numS->pop(numS);
            numS->push(numS, numS->pop(numS) / tmp);
            break;
        /* 数字部分 */
        default:
            numS->push(numS, ptr->elem);
        }
    }

    ElemType result = numS->pop(numS);
    numS->delete(numS);
    return result;
}

void printExpr(Expr expr) {
    LPos data = expr->headNode;
    for (LPos ptr = data->next; ptr; ptr = ptr->next) {
        switch ((int)ptr->elem) {
        case '+' + OPERATOR:
        case '-' + OPERATOR:
        case '*' + OPERATOR:
        case '/' + OPERATOR:
            printf("%c ", (int)ptr->elem - OPERATOR);
            continue;
        default:
            if (isFloat(ptr->elem))
                printf("%g ", (double)ptr->elem);
            else
                printf("%lld ", (long long)ptr->elem);
        }
    }
    putchar('\n');
}

ExprTree exprTree(char expr[]) {

}
