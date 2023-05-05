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

#define NUMAXLEN 10
#define OPERATOR 0xACEBDF
#define MAX_DIGIT 16


//-------------------------------------
// Structure Declaration
//-------------------------------------

typedef Link RPN;


//-------------------------------------
// Function Declaration
//-------------------------------------

// 中缀表达式转RPN (Reverse Polish Notation, 逆波兰)
RPN expr2RPN(char expr[]);
// RPN求值
double calcRPN(RPN rpn);
// RPN打印
void printRPN(RPN rpn);

#endif
