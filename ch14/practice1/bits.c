/*写四个函数操作整数第 n 位（n 从 0 起）：set_bit(置1)、clear_bit(清0)、
toggle_bit(翻转)、get_bit(取0/1)。main 给用例验证（如 0b1010 置第 0 位 → 0b1011）*/
#include <stdio.h>
 
unsigned set_bit(int num,int n){
    num|=(1u<<n);
    return num;
}

unsigned clear_bit(int num,int n){
    num&=~(1u<<n);
    return num;
}

unsigned toggle_bit(int num,int n){
    num^=(1u<<n);
    return num;
}

unsigned get_bit(int num,int n){
    int a=0;
    a=(num>>n)&1;
    return a;
}

int main(){
    unsigned int num=0;
    int n=0;
    printf("请输入一个整数和想要操作的位数：");
    scanf("%u %d",&num,&n);

    if(n<0||n>31){
        printf("位数必须在0-31之间");
        return 0;
    }
    
    unsigned int res1=set_bit(num,n);
    unsigned int res2=clear_bit(num,n);
    unsigned int res3=toggle_bit(num,n);
    unsigned int res4=get_bit(num,n);

    printf("%d操作第%d位置1为%d\n",num,n,res1);
    printf("%d操作第%d位清0为%d\n",num,n,res2);
    printf("%d操作第%d位翻转为%d\n",num,n,res3);
    printf("%d操作第%d位取位为%d\n",num,n,res4);
    return 0;

}
