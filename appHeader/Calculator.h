/**
 * @file Calculator.h
 * @brief 基于栈的简单整数计算器
 *
 * 表达式存储在Expr对象中.
 * Expr类实则为存储数的线性表 (链表). 运算符也表示为数, 但做上特殊的标记 (加上 `OPERATOR` 宏).
 * 由表达式树 (ExprTree类) 可以方便地得到前、中、后缀表达式.
 */
#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include ".general.h"
#include "Link.h"
#include "StackLink.h"
#include "QueueLink.h"
#include "BinaryTree.h"


//-------------------------------------
// Structure Declaration
//-------------------------------------

#define NUMAXLEN 10
#define OPERATOR 0xACBD
#define MAX_DIGIT 16

typedef Link Expr;
typedef BiTree ExprTree;


//-------------------------------------
// Function Declaration
//-------------------------------------

/**
 * @brief 中缀表达式转后缀表达式 (RPN, Reverse Polish Notation)
 *
 * 求后缀表达式的简便方法:
 * 把一个表达式的所有运算符按运算规则用括号括起来, 再从左向右依次把运算符移出到其对应的括号外面, 最后去除括号.
 * 例: (a-b)*(c+5) -> ((a-b)*(c+5)) -> ((ab)-(c+5)) -> ... -> ((ab)-(c5)+)* -> ab-c5+*
 *
 * @param exprString 待求的中缀表达式**字符串**
 * @return Expr 后缀表达式
 */
Expr expr2RPN(char exprString[]);
// RPN求值
ElemType calcRPN(Expr rpn);

/**
 * @brief 表达式树生成
 *
 * 构建思路:
 * 1. 数是叶子结点, 操作符是非叶子结点.
 * 2. 运算符有不同的优先级, 将操作符按优先级分组 (如加减一组, 乘除一组), 从高优先级的组开始构建.
 * 3. 构建单个操作符:
 *    操作符作为根结点, 左右两个数作为子节点, 得到一个满二叉树.
 * 4. 构建同优先级的操作符组:
 *    将该组操作符从表达式中提取出来, 从左到右依次构建 (见3.).
 *    若组中相邻的俩操作符在表达式中相邻, 则在构建完前一个后, 将得到的树作为构建后一个的"左数" (左孩子).
 *    若组中相邻的俩操作符在表达式中不相邻, 则分别构建独立的二叉树.
 * 5. 构建完操作符组后, 将得到的树视为构建下一优先级的数, 继续构建, 直到所有操作符构建完.
 *
 * @param expr 待构建的表达式
 * @return ExprTree 表达式树
 */
ExprTree exprTree(char expr[]);
/**
 * @brief 表达式树前序遍历
 *
 * @param tree
 * @return Expr 前缀表达式
 */
Expr tree2Prefix(ExprTree tree);
/**
 * @brief 表达式树中序遍历
 *
 * @param tree
 * @return Expr 中缀表达式
 */
Expr tree2Infix(ExprTree tree);
/**
 * @brief 表达式树后序遍历
 *
 * @param tree
 * @return Expr 后缀表达式 (RPN)
 */
Expr tree2Postfix(ExprTree tree);

// 打印Expr对象
void printExpr(Expr expr);


#endif
