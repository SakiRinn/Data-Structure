#include "Calculator.h"


int main() {
    char expr[] = "1+2*(3-(4+6))/5";
    RPN rpn = expr2RPN(expr);
    printRPN(rpn);
    return 0;
}