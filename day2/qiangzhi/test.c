#include <stdio.h>
int main(void)
{
    printf("%d\n", (int)12.7); // 截断小数，输出12

    int a = 5, b = 2;
    printf("整数除法 a/b = %d\n", a / b);
    printf("强制转换浮点除法 (double)a / b = %f\n", (double)a / b);
    printf("错误写法 (double)(a/b) = %f\n", (double)(a / b));

    double num = 3.99;
    int res = (int)num;
    printf("num = %lf, res = %d\n", num, res); // num不变，res=3
    return 0;
}
