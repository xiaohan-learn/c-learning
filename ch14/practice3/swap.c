/*① 异或不用临时变量交换两数 a^=b;b^=a;a^=b; 
② 判断 2 的幂 n>0 && (n&(n-1))==0 ③ 取奇偶 x&1*/
#include <stdio.h>
int main()
{
    int a=0;
    int b=0;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    printf("交换前a=%d,b=%d\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("交换后a=%d,b=%d\n",a,b);
    return 0;
}

