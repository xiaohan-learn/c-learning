/*练习1（带参宏）​：让你先写「错误版」SQR(x) 再写「正确版」，
main 里故意测 SQR(a+1)、SQR(++i)、MAX3 嵌套，对照「验收输出」看坑在哪；
并提示把「双括号 + 别传副作用」补进 BUG.md 待补区。*/
/* 在 main 里做对比测试：
   - 错误版 `SQR(a+1)`（a=3）：看输出是不是你以为的 16。
   - 正确版 `SQR(a+1)`：确认输出 16。
   - `SQR(++i)`（i 初值 1）：看 i 最后变成多少。
   - `MAX3(a+b, a*b, a-b)`：嵌套调用，确认结果对手算。*/
   #include <stdio.h>
   #define SQR1(x) (x*x)
   #define SQR2(x) ((x)*(x))
   #define MAX3(x,y,z) ((x)>(y)?(x)>(z)?(x):(z):(y)>(z)?(y):(z))

   int main(){
    int a=3;
    int i=1;
    printf("错误版输出：%d\n",SQR1(a+1));//a+1*a+1=7
    printf("正确版输出：%d\n",SQR2(a+1));//(a+1)*(a+1)=16
    printf("初始值i=%d\n",i);  //1
    printf("SQR(++i)=%d\n",SQR2(++i));/*GCC会先把表达式里所有前置自增全部执行完成，再取值计算
                                       ++i=2;++i=3;SQR(++i)=3*3=9 */
    printf("最后i值=%d\n",i); //3

    int b=3,c=5;
    printf("MAX3=%d\n",MAX3(b+c,b*c,b-c)); //15
    return 0;
   }