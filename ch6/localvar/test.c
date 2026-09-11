#include <stdio.h>

/*
 * 7.3 本地变量：作用域(scope) 与 生存期(lifetime)
 *
 * 一句话结论：
 *   局部变量的"活动范围"由【所在的 {} 决定】——出了花括号就消失，
 *   不同函数里的同名变量是【各自独立的两份】，互不影响。
 */

/* 实验一用：f 里有自己的 x */
void f(void) {
    int x = 100;
    printf("  [f   ] 我这里也有一份 x = %d\n", x);
}

/* 实验五用：证明两个函数算不出对方的局部变量，只能靠参数拿数据 */
int add_one(int n) {
    return n + 1;
}

int main(void) {
    int x = 1;
    printf("=== 实验一：不同函数里的同名变量，是两份 ===\n");
    printf("[main] 我的 x = %d\n", x);
    f();
    printf("[main] 调用 f 之后，我的 x = %d   <-- 没被改，它是我的\n\n", x);

    printf("=== 实验二：块作用域 {} ===\n");
    printf("[main] 块之前 x = %d\n", x);
    {
        int x = 999;   // 新的 x，只在花括号里活着
        printf("[块内] x = %d   <-- 这是块自己的 x\n", x);
    }
    printf("[main] 出块后 x = %d   <-- 又看到外面那个\n\n", x);

    printf("=== 实验三：for 里的变量也是块作用域 ===\n");
    for (int i = 0; i < 4; i++) {
        int y = i * i;
        printf("[for ] 第 %d 轮：i=%d  y=i*i=%d\n", i + 1, i, y);
    }
    /* 取消下面这行的注释会【编译报错】：i / y 出了 for 就不存在了 */
    /* printf("出循环还能用 i 吗？i=%d\n", i); */
    printf("\n");

    printf("=== 实验四：未初始化的局部变量是垃圾值 ===\n");
    int junk;
    printf("[main] junk = %d   <-- 不确定，是内存里的残留，千万别依赖\n\n", junk);

    printf("=== 实验五：函数之间只能靠参数/返回值传数据 ===\n");
    int n = 5;
    int r = add_one(n);
    printf("[main] n = %d, add_one(n) = %d   <-- n 没变，结果靠 return 拿回来\n", n, r);

    return 0;
}
