/*enum Weekday {MON=1,TUE,...,SUN}，写函数 const char* weekday_name(int d) 
用 switch 把数字转成中文星期名；main 里测试 1→"周一"、7→"周日"、0→"无效"*/
/*定义一个枚举表示星期，再写一个函数把数字翻译成中文星期名。
要求
enum Weekday { MON=1, TUE, WED, THU, FRI, SAT, SUN };
（注意从 1 开始，TUE 自动是 2、WED 是 3……）
写一个函数 const char* weekday_name(int d)，用 switch 把 1→"周一"、2→"周二"…7→"周日"，
其他值（如 0、8）返回 "无效"。
main 里测试至少这 4 组并打印：1、7、3、0，每行形如 数字 1 -> 周一。
验收：四个用例输出都正确，且 0 走 "无效" 分支（验证 default 覆盖）。

提示：const char* 返回字符串字面量是安全的（字面量存在只读区，不会随函数返回失效）。*/
#include <stdio.h>
enum Weekday{
    MON=1,TUE,WED,THU,FRI,SAT,SUN
};
const char*weekday_name(enum Weekday d){
    switch(d){
        case MON: return "周一";
        case TUE: return "周二";
        case WED: return "周三";
        case THU: return "周四";
        case FRI: return "周五";
        case SAT: return "周六";
        case SUN: return "周日";
        default:  return "无效";
    }
}

int main(){
    
    printf("1->%s\n",weekday_name(1));
    printf("7->%s\n",weekday_name(7));
    printf("3->%s\n",weekday_name(3));
    printf("0->%s\n",weekday_name(0));
    
    return 0;
}
         
    