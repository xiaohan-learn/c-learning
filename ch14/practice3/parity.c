/*① 异或不用临时变量交换两数 a^=b;b^=a;a^=b; 
② 判断 2 的幂 n>0 && (n&(n-1))==0 ③ 取奇偶 x&1*/

#include <stdio.h>
int main()
{
    int num=0;
    printf("请输入一个整数：");
    scanf("%d",&num);
    if((num&1)==1){
        printf("%d为奇数\n",num);
    }else if((num&1)==0){
        printf("%d为偶数\n",num);
    }
    return 0;
}