/*基于栈的简单计算器*/
#ifndef _CALCULATOR_H_
    #define _CALCULATOR_H_

#include "Link.h"
#include "StackLink.h"
#define NUMAXLEN 10
#define OPTOR 0xACE

/*Function Declaration*/
//将中缀表达式转换成后缀表达式 
Link RevPolish(char expr[]);
//后缀表达式求值 
int CalcRev(Link revp);

#endif