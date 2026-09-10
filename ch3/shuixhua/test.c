#include <stdio.h>
int main(void)
{
    int n=0;
    scanf ("%d",&n);
    int first=1;//N 位数的起始数字。比如 N=3，三位数从 100 开始，first最后结果就是 100。
    int i=1;    //循环计数器 i，用于计算 first = 10^(n‑1)。
    while(i<n){
        first*=10;
        i++;   //N=3：循环执行 2 次，first =1*10*10 =100，得到最小的 N 位数。
    }//printf("first=%d\n",first);
    i=first;   //重置 i，让 i 从最小 N 位数开始遍历。N=3 时 i=100。
    while(i<first*10){  //遍历全部 N 位数.
        int t=i;      //临时变量t，复制当前数字i。后面要拆分每一位，不能直接修改 i。
        int sum=0;    //保存「每一位数字 N 次方的累加和」，每次新数字都重置为 0
        while(t>0){   //循环拆分 t 的每一位，t 不断除以 10，直到 t 变成 0。
            int b=t%10;  //取个位
            t/=10;       //去掉已经取出的个位
            int c=b;     //用来计算 b的n次方，初始值等于当前位数字 b。
            int d=1;     //d 是次方循环计数器
            while (d<n){
                c*=b;
                d++;
            }            //循环 n‑1 次，完成求 bⁿ。
            sum+=c;      //把这一位的 N 次方加到总和。
        }            //内层 while (t>0) 结束，当前数字 i 所有位都拆分、计算完毕。
        if (sum==i){  //判断条件：各位 N 次方之和sum是否等于原数字 i。满足就是水仙花数。
            printf("%d\n",sum);
        }
        i++;
    }    //while(i<first*10)大循环结束，全部 N 位数遍历完毕。
    return 0;
}
