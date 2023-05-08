#include "Calculator.h"


int main() {
    char expr[] = "2*(9+6/3-5)+4";
    RPN rpn = expr2RPN(expr);
    printRPN(rpn);
    printf("%d \n", calcRPN(rpn));
    return 0;
}