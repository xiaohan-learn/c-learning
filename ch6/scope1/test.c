/*
 * ch6/scope1 —— 作用域与生存期 三个实验（参考实现）
 *
 * 目标：亲手验证三件事
 *   1. 值传递：函数内改了参数，main 里的原件不变
 *   2. 块作用域：内层 {} 的变量会"遮蔽"外层同名变量
 *   3. for 循环里声明的变量，出循环就不可见（编译报错）
 *
 * 编译：gcc -Wall -o test.exe test.c
 * 运行：./test.exe
 */

#include <stdio.h>

/* ---------- 实验1：值传递验证 ---------- */
int increase(int n)
{
    n = n + 1;                       /* 改的是 n 的副本 */
    printf("  [increase 内] n = %d （这是副本，已 +1）\n", n);
    return n;                        /* 顺手演示：把结果交回去 */
}

/* ---------- 实验2：块作用域遮蔽 ---------- */
void shadow_demo(void)
{
    int v = 10;                      /* 外层 v */
    printf("  [shadow] 外层 v = %d\n", v);
    {
        int v = 20;                  /* 内层 v，遮蔽了外层的 v */
        printf("  [shadow] 内层块 v = %d （遮蔽了外层）\n", v);
    }
    /* 出了内层块，内层 v 已销毁，看到的又是外层 v */
    printf("  [shadow] 出块后 v = %d （恢复为外层）\n", v);
}

int main(void)
{
    /* ===== 实验1：increase 值传递 ===== */
    int n = 5;
    printf("调用前 main 的 n = %d\n", n);
    int r = increase(n);            /* 把 n 的值（5）传进去 */
    printf("调用后 main 的 n = %d （没变！）\n", n);
    printf("increase 的返回值 r = %d\n", r);

    /* ===== 实验2：块作用域遮蔽 ===== */
    shadow_demo();

    /* ===== 实验3：for 循环变量的作用域 ===== */
    /*
     * 下面这段代码如果取消注释，编译会直接报错：
     *
     *   for (int i = 0; i < 3; i++) {
     *       printf("循环内 i = %d\n", i);
     *   }
     *   printf("循环外 i = %d\n", i);     // ❌ 'i' undeclared
     *
     * gcc -Wall 报错原文（节选）：
     *   scope1/test.c: 在函数 'main' 中:
     *   scope1/test.c:62:29: error: 'i' undeclared (first use in this function)
     *      62 |     printf("循环外 i = %d\n", i);
     *         |                             ^
     *   注：每个未声明的标识符只报一次，后面的使用都不再提示
     *
     * 原因：for 头里写的 int i 作用域仅限于 for 的循环体，
     *       一旦跳出 for，i 就销毁了，循环外再引用就是"未声明"。
     *
     * 想让循环外还能用，把声明提到外面：
     */
    int j;
    for (j = 0; j < 3; j++) {
        printf("循环内 j = %d\n", j);
    }
    printf("循环外 j = %d （因为声明在外面，所以可见）\n", j);

    return 0;
}
