/*写一个 int next_id(void) 函数，内部用 static int counter=0;，每次调用 counter++ 并返回。
main 里连调 4 次，验证它每次返回 1/2/3/4（证明 static 跨调用保留了值，
对比"非 static 局部变量"每次都归零）*/
/*验证 static 局部变量的"值会保留"特性，并和非 static 对比。

写函数 int next_id(void)：内部 static int counter = 0;，每次进来 counter++ 后 return counter;
再写一个对照函数 int next_id_nostatic(void)：把 static 去掉，其它一样（每次返回 1）
main 里分别连调 next_id() 4 次、next_id_nostatic() 4 次，打印每次返回值。
验收：next_id 输出 1 2 3 4（static 保留值），next_id_nostatic 输出 1 1 1 1（每次归零）
——两组对比直观体现 static 的作用。

提示：static int counter = 0; 这个初始化只执行一次（第一次进入函数时），
后面再调用不会再归零，这正是它能"记住"的原因。*/                     
#include <stdio.h>

int next_id(void){
    static int count=0;
    count++;
    return count;
}

int next_id_nostatic(void){
    int count=0;
    count++;
    return count;
}

int main(){
    printf("static跨调%d\n",next_id());
    printf("static跨调%d\n",next_id());
    printf("static跨调%d\n",next_id());
    printf("static跨调%d\n",next_id());

    printf("nostatic跨调%d\n",next_id_nostatic());
    printf("nostatic跨调%d\n",next_id_nostatic());
    printf("nostatic跨调%d\n",next_id_nostatic());
    printf("nostatic跨调%d\n",next_id_nostatic());
return 0;
}
