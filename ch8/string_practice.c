#include <stdio.h>
#include <ctype.h>   // 想用 isalpha/isdigit 就包含；不想用也可直接比 ASCII

#define LEN 100

/* 统计字符串 str 中的字母、数字、空格个数，并直接打印结果（不返回值，不涉及指针） */
void count_chars(char str[]) {
    int letters = 0, digits = 0, spaces = 0;
    // 用 '\0' 作为结束符来终止循环，而不是固定 100
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else if ((str[i] >= 'a' && str[i] <= 'z') ||
                   (str[i] >= 'A' && str[i] <= 'Z')) {
            letters++;   // 小写和大写字母都算"字母"，合并到一个判断里
        }
    }
    printf("字母个数%d个\n", letters);
    printf("数字个数%d个\n", digits);
    printf("空格个数%d个\n", spaces);
}

/* 原地反转字符串 str（用下标首尾交换，不涉及指针） */
void reverse_str(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;   // 先算出字符串长度
    int left = 0, right = len - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

/* 判断回文：正读反读一样返回 1，否则返回 0 */
int is_palindrome(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    int left = 0, right = len - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;   // 发现一处不一致就立刻返回"不是"
        }
        left++;
        right--;
    }
    return 1;         // 全部一致才返回"是"
}

int main() {
    char str[LEN];
    printf("请输入一个字符串(不含空格): ");
    scanf("%s", str);   // %s 遇空格停止，练单词够用

    count_chars(str);

    // 先判断回文（用原串），再反转（reverse 会改掉原串）
    if (is_palindrome(str)) {
        printf("是回文\n");
    } else {
        printf("不是回文\n");
    }

    reverse_str(str);
    printf("反转后的字符串: %s\n", str);

    return 0;
}
