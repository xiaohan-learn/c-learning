/*演示全局变量：在文件顶定义 int g_count;，
两个函数都读写它，main 里调这两个函数看 g_count 怎么累计变化。
再试把 g_count 改成 static int g_count;（文件内私有），理解两者的区别*/
/*演示全局变量的"跨函数共享"，并理解 static 加在全局变量前的区别。
要求（分两步，先写第一步）​
在文件最外层（所有函数之外）定义 int g_count = 0;
写两个函数都操作它：void inc(void) 里 g_count++;、void dec(void) 里 g_count--;
main 里调 inc() 三次、dec() 一次，打印每次后的 g_count，
验证它确实在多个函数间共享累加（最终应为 2）。

进阶思考（不用改文件，先在注释里写结论）​：如果把 int g_count 改成 static int g_count，
对"本文件内多个函数共享"有没有影响？把它和"另一个 .c 文件想用这个变量"的场景联系起来想一想
（提示：static 全局 = 只本文件可见，外部文件 extern 也拿不到）。*/
#include <stdio.h>
 int g_count=0;


 int inc(void){
    //static int g_count=0;
    g_count++;
    return g_count;
 }

 int dec(void){
    //static int g_count=0;
    g_count--;
    return g_count;
 }

 int main(){
    printf("调用inc中g_count=%d\n",inc());
    printf("调用inc中g_count=%d\n",inc());
    printf("调用inc中g_count=%d\n",inc());
    printf("调用dec中g_count=%d\n",dec());
    return 0;
 }