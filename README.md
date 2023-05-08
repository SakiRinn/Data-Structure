# 数据结构

纯C语言实现，支持面向对象和泛型。


## 面向对象

本项目中的所有容器类均为面向对象类，通过函数指针实现方法域。
每一个容器类对应一个头文件，位于 `include` 路径下。

函数指针的初始化在初始化函数 `<Class>_init` 中进行，因此使用容器类之前必须初始化。

以链表为例，用法为
```C
#include "Link.h"

int main()
{
    Link L = Link_init();
    /* code... */
}
```

此外，由于C语言无法轻易地隐藏 `this/self` 参数，面向对象类的第一个参数**一般**为对象自身。对应的形参为 `self` .
数据结构的类型实现通常为指针，因此调用方法的语法是 `<object>-><method>` .

**<font color=Red>注意：</font>** 有例外，比如链表的 `insertPos` 方法。请通过形参名是否为 `self` 区分方法是否为例外。


## 泛型

通过带参宏定义实现，具体位于 `include/generic` 路径下。

在声明泛型类之前不但要 `#include` 对应的头文件，还需先调用一次宏，格式为 `GENERIC_<CLASS>(<ElemType>)` .

泛型类涉及到的类型名格式均为 `<Class>_<ElemType>` ，包括内部的子类型。
声明泛型类后，在使用前**必须**进行初始化，函数名为 `<Class>_<ElemType>_init` .

若类型具有 `delete` 方法，在使用完毕后**必须**调用，以释放内存。

以元素类型为double的链表为例，用法为
```C
#include "Link.h"
GENERIC_LINK(double)

int main()
{
    Link_double L = Link_double_init();
    /* code... */
    L->delete(L);
    return 0;
}
```

请不要直接将指针类型作为泛型，建议使用 `u_int64_t` 代替。

已经在 `.general.h` 头文件里将 `pointer` 作为 `u_int64_t` 的别名，建议在代码中使用 `pointer` 类型以保证更好的可读性。(例见 `BinaryTree.c` )

> **<font color=Red>注意：</font>** 若泛型类的实现基于某些类，需要在调用其泛型宏之前调用基类的泛型宏。
>
> 例如，以链表为基础的泛型类 (名称里带`Link`)，使用前必须先调用一次 `Link` 的泛型宏。

以元素类型为double的链栈为例，用法为
```C
#include "StackLink.h"
GENERIC_LINK(double)        // IMPORTANT
GENERIC_STACK_LINK(double)

int main()
{
    LStack_double LS = LStack_double_init();
    /* code... */
    LS->delete(LS);
    return 0;
}
```