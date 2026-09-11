 /*在 D:\code_c 下新建 ch8_array/ 目录，创建 scores.c
 定义 int scores[10]，用 for 循环从键盘读入 10 个整数并打印确认
预期产出：scores.c 可编译，读入并打印 10 个数验证无误*/

#include <stdio.h>
int main()
{
    int scores[10];
    int i;
    for(i=0;i<10;i++)
    {
    scanf("%d",&scores[i]);
    }
    for(i=0;i<10;i++)
    {
    printf("%d\n",scores[i]); 
    }
    return 0;
}
