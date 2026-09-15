/* 练习3：用 p++ / p-- 实现字符串长度 my_strlen（不使用库函数 strlen） */
#include <stdio.h>

/* 返回字符串 str 的长度（不含 '\0'），不使用库函数 */
int my_strlen(char *str) {
    char*p=str;
    while(*p!='\0'){
        p++;
    }
    return p-str;
    // TODO: 用 char *p = str; 当 *p != '\0' 时 p++;
    //       最后返回 p - str（指针相减 = 字符个数）
    // 进阶：试试用 p-- 从 '\0' 往回找也行，体会 p++ 与 p-- 对称
}

int main() {
    char s[] = "Hello";
    int n=my_strlen(s);
    printf("长度 = %d\n", n);   // 期望输出 5
    return 0;
}
