#include <stdio.h>

#define ROW 3
#define COL 3

// 把矩阵 a 转置（行列互换）后存入矩阵 b
// 转置规则：b[j][i] = a[i][j]
// 注意：a 是 ROW x COL，b 是 COL x ROW
// TODO: 实现这个函数
void transpose(int a[][COL], int b[][COL], int row, int col) {
    // 提示：双重循环遍历 a，把 a[i][j] 放到 b[j][i]
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            b[j][i]=a[i][j];
        }
    }
}

int main() {
    int a[ROW][COL];
    int b[COL][ROW];

    printf("请输入 %d x %d 矩阵:\n", ROW, COL);
    // TODO: 用双重 for 循环读入 a[i][j]
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            scanf("%d", &a[i][j]);

    transpose(a, b, ROW, COL);

    printf("转置后的矩阵:\n");
    // TODO: 用双重 for 循环打印 b
    // 注意 b 是 COL 行、ROW 列，循环边界别写反
    for (int i = 0; i < COL; i++) {
        for (int j = 0; j < ROW; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    return 0;
}
