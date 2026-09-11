/*
 * ch6/return_proto —— 函数返回值 与 函数声明（原型）
 *
 * 两个重点：
 *   1. return 把"结果"从被调函数交回主调函数；返回类型要匹配
 *   2. 函数写在 main 后面时，必须先在前面"声明原型"，否则编译不过
 *
 * 编译：gcc -Wall -o test.exe test.c
 * 运行：./test.exe
 */

#include <stdio.h>

/* ===== 函数声明（原型 / prototype）=====
 * 告诉编译器："下面会有一个叫 max 的函数，接收两个 int，返回一个 int"
 * 参数名可以省，只写类型——编译器只关心类型，不关心名字
 * 注意结尾有分号 ';'，这是"声明"不是"定义"
 */
int max(int, int);

int main(void)
{
    int a = 3, b = 7;
    /* 调用时编译器已经知道 max 的长相，能正确检查参数和返回值 */
    printf("max(%d, %d) = %d\n", a, b, max(a, b));
    return 0;                       /* main 的返回类型也是 int */
}

/* ===== 函数定义 =====
 * 这里才是真正写函数体的地方；参数名不能省，要拿来用
 */
int max(int x, int y)
{
    return x > y ? x : y;           /* return 把较大的那个交回去 */
}
