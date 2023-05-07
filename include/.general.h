#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

// 错误返回值
#define ERROR 0x1FFF


//-------------------------------------
// Type Declaration
//-------------------------------------

// 下标类型 (由于可能为-1, 因此不能为unsigned类型)
typedef u_int64_t ind_t;
// 全局数据类型
typedef int ElemType;
// 指针类型 (用于泛型类)
typedef u_int64_t pointer;


//-------------------------------------
// Function Declaration
//-------------------------------------

/**
 * @brief 检测两个浮点数是否相等
 *
 * @param a 待比较数
 * @param b 待比较数
 * @return true/false
 */
static inline bool equal(double a, double b) {
    return (fabs(a - b) < 1e-6) ? true : false;
}

/**
 * @brief 判断是否为大端存储
 *
 * @return true/false
 */
static inline bool isBigEndian() {
    union Num {
        int a;
        char b;
    } num;
    num.a = 0x1234;
    return num.b == 0x12 ? true : false;
}

/**
 * @brief 检测一个数是否为浮点数
 *
 * @param addr 待检测数的地址
 * @param size 待检测数的size, 一般用sizeof作为输入
 * @return true/false
 *
 * @attention 不建议直接调用, 使用 `isFloat` 宏代替.
 * `isFloat(x)` - x为待检测**变量**.
 */
static bool _isFloat(double value, void *addr, size_t size) {
    if (size == 4) {
        // is float?
        u_int32_t num = 0;
        for (int i = 0; i < 4; i++)
            num += (u_int32_t)((unsigned char *)addr)[i] << (8 * i);
        return num != (u_int32_t)value ? true : false;
    } else if (size == 8) {
        // is double?
        u_int64_t num = 0;
        for (int i = 0; i < 8; i++)
            num += (u_int64_t)((unsigned char *)addr)[i] << (8 * i);
        return num != (u_int64_t)value ? true : false;
    } else
        return false;
}
#define isFloat(x) _isFloat(x, &x, sizeof(x))


#endif
