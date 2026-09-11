#include <stdio.h>

/*
 * 值传递实验（对应翁恺 7.2.2 参数传递）
 *
 * 核心结论：C 语言函数调用是【值传递】——把实参的值【复制】一份给形参。
 *   形参 a、b 只是 main 里 a、b 的"替身"，在函数里怎么改替身，
 *   都碰不到 main 里的原变量。
 *
 * 下面的 swap_by_pointer 先放这，等你学到指针再回头看，会恍然大悟：
 *   想真正交换原变量，就得把"地址"传进去，让函数改地址上的值。
 */

// 值传递版：a、b 是 main 里 a、b 的【副本 / 替身】
void swap_by_value(int a, int b) {
    printf("  [函数内] 收到副本 a=%d, b=%d\n", a, b);
    int t = a;
    a = b;
    b = t;
    printf("  [函数内] 交换副本后 a=%d, b=%d\n", a, b);
}

// 指针传递版：拿到的是 main 里 a、b 的【地址】，改的是原值
void swap_by_pointer(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int a = 8, b = 9;

    printf("=== 实验一：值传递 swap_by_value ===\n");
    printf("调用前(main)：a=%d, b=%d\n", a, b);
    swap_by_value(a, b);
    printf("调用后(main)：a=%d, b=%d  <-- 没变！函数只改了替身\n\n", a, b);

    printf("=== 实验二：指针传递 swap_by_pointer（先认识一下）===\n");
    printf("调用前(main)：a=%d, b=%d\n", a, b);
    swap_by_pointer(&a, &b);
    printf("调用后(main)：a=%d, b=%d  <-- 真交换了！因为传的是地址\n", a, b);

    return 0;
}
