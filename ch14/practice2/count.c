/*统计 unsigned int 二进制里 1 的个数，两种方法：① 逐位 (x>>i)&1 循环 32 次 
② 经典 x &= (x-1) 每次清最低位 1 直到 0。对比两法结果*/

#include <stdio.h>

int count1(int num)
{
    int cnt1=0;
    for(int i=0;i<32;i++){
        if(((num>>i)&1)==1){
            cnt1++;
        }
    }
    return cnt1;
} 

int count2(int num)
{
    int cnt2=0;
    while(num!=0){
    num&=(num-1);
    cnt2++;
    }
    return cnt2;
}

int main()
{
    int x=0;
    printf("请输入一个整数：");
    scanf ("%d",&x);
    int res1=count1(x);
    int res2=count2(x);
    printf("逐位(x>>i)&1循环中二进制里1的个数%d\n",res1);
    printf("经典 x &= (x-1)中二进制里1的个数%d\n",res2);
    return 0;
}