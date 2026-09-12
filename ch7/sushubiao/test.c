#include <stdio.h>
int main()
{
    const int number=25;
    int isprime[number];
    int x;
    // 初始化：全部标记为1（是素数）
    for(int i=0;i<number;i++){
         isprime[i]=1;//假设是素数
    }
    isprime[0] = 0;
    isprime[1] = 0;  // 0、1不是素数

    for(x=2;x<number;x++){
        if(isprime[x]){  // 如果x是素数，标记它所有倍数
            for(int i=2;i*x<number;i++){
                isprime[i*x]=0;
            }
        }
    }
    for(int i=2;i<number;i++){
        if (isprime[i]){
            printf("%d\t",i);
        }
    }
    return 0;
}