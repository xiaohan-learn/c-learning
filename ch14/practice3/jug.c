/*① 异或不用临时变量交换两数 a^=b;b^=a;a^=b; 
② 判断 2 的幂 n>0 && (n&(n-1))==0 ③ 取奇偶 x&1*/
#include <stdio.h>
int main(){
    int num=0;
    printf("请输入一个整数：");
    scanf("%d",&num);
    int cnt=0;
    for(int i=0;i<32;i++){
        if(((num>>i)&1)==1)
        cnt++;
    }
    if (num>0&&cnt==1){  //2的幂的数二进制中只有一个1；
        printf ("%d是2的幂\n",num);
    }else{
        printf("%d不是2的幂\n",num);
    }
    return 0;
}