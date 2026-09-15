/* 练习2：用指针运算实现数组复制（从 src 搬到 dst，不用下标） */
#include <stdio.h>

#define N 5

/* 把 src 的前 n 个元素复制到 dst（用指针 p 遍历，不用下标） */
void copy_arr(int *dst, int *src, int n) {
    int *p=src;
    int *q=dst;
    for(p=src;p<src+n;p++){
        *q=*p;
        q++;
    }
    // TODO: 用 int *p = src, *q = dst;
    //       循环 n 次：*q = *p; 然后 p++; q++;
    //       注意：dst 必须指向足够大的空间（main 里已开好 N 个）
}

int main() {
    int src[N] = {1, 3, 5, 7, 9};
    int dst[N];

    copy_arr(dst, src, N);

    printf("复制结果: ");
    for (int *p=dst; p <dst+ N; p++) {
        printf("%d ", *p);   // 期望输出 1 3 5 7 9
    }
    printf("\n");
    return 0;
}
