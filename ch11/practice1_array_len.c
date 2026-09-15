/* 练习1：用指针相减 p-q 求数组长度（替代 sizeof，用 -1 作哨兵） */
#include <stdio.h>

/* arr 以 -1 结尾（哨兵），返回元素个数（不含 -1） */
int array_len(int *arr) {
    int *p=arr;
    while(*p!=-1){
        p++;
    }
    return p-arr;
    // TODO: 用指针 p 从 arr 开始往后走，直到 *p == -1
    //       返回 end - arr（指针相减得到的是"隔了几个元素"，不是字节数）
    // 提示：int *p = arr; while (*p != -1) { p++; }  return p - arr;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, -1};  // -1 是哨兵，不算元素
    int n = array_len(arr);
    printf("数组长度 = %d\n", n);   // 期望输出 6
    return 0;
}
