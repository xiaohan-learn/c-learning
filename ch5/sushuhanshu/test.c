#include <stdio.h>
int isprime(int i){
    int ret=1;
    if(i<2){
        return 0;
    }
    int k;
    for(k=2;k<i;k++){
        if(i%k==0){
           ret=0;
           break;
        } 
    }
        return ret;  
}
int main()
{
    int m,n;
    scanf ("%d %d",&m,&n);
    int sum=0;
    int i;
    for(i=m;i<=n;i++){
        if(isprime(i)){
            sum+=i;
        }
    }
    printf("%d\n",sum);
    return 0;
}  
