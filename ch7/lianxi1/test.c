/*需求：统计用户输入的数字中，0~9 每个各出现了多少次。*/
#include<stdio.h>
int main()
{
    const int number=10;
    int x;
    scanf("%d",&x);
    int cnt[number];
    for(int i=0;i<number;i++){
        cnt[i]=0;//初始化为0
    }
    while(x!=-1){
        if(x>=0&&x<=9){
            cnt[x]++;
        }
         scanf("%d",&x);//继续读取下一个整数
    }
    for(int i=0;i<number;i++){
        printf("%d出现了%d次\n",i,cnt[i]);
         
    }

    return 0;

}
