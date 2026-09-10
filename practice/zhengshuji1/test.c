#include <stdio.h>
int main (void)
{
    int a=0;
    scanf("%d",&a);
    int i,j,k;
    int cnt=0;
    for(i=a;i<=a+3;i++){
        for(j=a;j<=a+3;j++){
            for(k=a;k<=a+3;k++){
                if(i!=j&&i!=k&&j!=k){
                    cnt++;
                    printf("%d",i*100+j*10+k);
                    if(cnt==6){
                        printf ("\n");
                        cnt=0;}
                        else{printf (" ");}
                    

                }
            }
        }
    }
    return 0;
}