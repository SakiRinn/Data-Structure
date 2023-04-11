#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 错误返回值
#define ERROR 0x1FFF

// 下标类型 (由于可能为-1, 因此不能为unsigned类型)
typedef long ind_t;
// 长度类型
typedef size_t len_t;
// 全局数据类型
typedef int ElemType;

#endif
