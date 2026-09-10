#include <stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int sum=0;
    int i;
   // if(m==1){m=2;}
    for(i=m;i<=n;i++){
        int k;
        int isprime=(i>=2);//是素数
        for(k=2;k<i;k++){
            if(i%k==0){
                isprime=0;
                break;
            }
        }
            if(isprime)
            {
             sum+=i;
            }
    }
    printf("%d\n", sum);
    return 0;
}