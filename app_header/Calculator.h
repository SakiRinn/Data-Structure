/**
 * @file Calculator.h
 * @brief 基于栈的简单整数计算器
 *
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Link.h"
#include "StackLink.h"
#include "QueueLink.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

#define NUMAXLEN 10
#define OPERATOR 0xACBD
#define MAX_DIGIT 16

typedef Link RPN;


//-------------------------------------
// Function Declaration
//-------------------------------------

/**
 * @brief 中缀表达式转后缀表达式 (RPN, Reverse Polish Notation)
 *
 * @details 求后缀表达式的简便方法:
 * 把一个表达式的所有运算符按运算规则用括号括起来, 再从左向右依次把运算符移出到其对应的括号外面, 最后去除括号.
 * 例: (a-b)*(c+5) -> ((a-b)*(c+5)) -> ((ab)-(c+5)) -> ... -> ((ab)-(c5)+)* -> ab-c5+*
 *
 * @param expr 待求的中缀表达式
 * @return 后缀表达式对象 (实则为线性表)
 */
RPN expr2RPN(char expr[]);
// RPN求值
double calcRPN(RPN rpn);
// RPN打印
void printRPN(RPN rpn);


#endif
