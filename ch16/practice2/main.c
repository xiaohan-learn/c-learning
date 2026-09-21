/* 目标
把「一个文件搞定」改造成「头文件 + 实现文件 + 主文件」，并亲手 `gcc` 编译链接，理解分文件。
你要写什么（三个文件）
挑 ch7 或 ch10 一个旧练习，例如「数组求最大值」或「指针遍历求和」，拆成：
- `calc.h`：放函数原型 + 头文件守卫。
- 守卫写法：`#ifndef CALC_H` / `#define CALC_H` / ... / `#endif`（或 `#pragma once`）。
- 例：`int array_max(int arr[], int n);`
- calc.c`：放函数实现（`#include "calc.h"` 后写函数体）。
- main.c`：`#include "calc.h"`，在 main 里准备数据、调用、打印。*/
#include <stdio.h>
#include "calc.h"
extern int g_count;

int main()
{
    int scores[5];
    printf("请输入5个数字\n");
    for(int i=0;i<5;i++){
        scanf("%d",&scores[i]);    
    }
    printf("调用函数前g_count=%d\n",g_count);

    int max=max_score(scores, 5);
    double avg=avg_score(scores, 5); 
    printf("最高分是%d\n",max);
    printf("平均分是%.2f\n",avg);
    printf("调用函数后g_count=%d\n",g_count);
    
    return 0;
}
