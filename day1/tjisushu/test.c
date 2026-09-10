#include <stdio.h>
int main(void)
{
    int m,n;
    scanf ("%d %d",&m,&n);
    if(m==1){
        m=2;
    }
    int cnt=0;
    int sum=0;
    int i=0;
    for(i=m;i<=n;i++){
        int isprime=1;
        int k=0;
        for(k=2;k<i;k++){
            if(i%k==0){
                isprime=0;
                break;
            }
        }
        if(isprime==1){
            cnt++;
            sum+=i;
        }
    }
    printf ("%d %d\n",cnt,sum);
    return 0;

}