/**
 * @file Calculator.h
 * @brief 基于栈的简单整数计算器
 *
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Link.h"
#include "StackLink.h"

#define NUMAXLEN 10
#define OPERATOR 0xACEBDF


//-------------------------------------
// Structure Declaration
//-------------------------------------

GENERIC_LINK(int);
GENERIC_LINK(double);
GENERIC_STACK_LINK(int);
GENERIC_STACK_LINK(double);
typedef Link_int RPN;

//-------------------------------------
// Function Declaration
//-------------------------------------

// 将中缀表达式转换成后缀表达式 (a.k.a RPN, Reverse Polish Notation, 逆波兰)
RPN expr2RPN(char expr[]);
// 后缀表达式求值
double calcRPN(RPN revp);

#endif