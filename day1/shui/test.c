#include<stdio.h>
int main(void)
{
    int n=0;
    scanf ("%d",&n);
    int first=1;
    int i=1;
     for(i=1;i<n;i++){
        first*=10;
         }
    for(i=first;i<first*10;i++){
        int t=i;
        int sum=0;

        for(t=i;t>0;t/=10){
            int b=t%10;
            int c=b;

            for (int d=1;d<n;d++){
                c*=b;
            }sum+=c;
        }if(sum==i){
            printf ("%d\n",sum);
        }

    }
    
    return 0;
}